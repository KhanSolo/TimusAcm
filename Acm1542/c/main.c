#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "profiler2.h"

#define MAX_WORD_LEN    16        // максимальная длина слова
#define TOP_K           10        // не более слов в выдаче
#define HASH_SIZE       100999    // простое большое число

// ---------- СЛОВО (символы, частота) ----------
typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} Word;

// ---------- ARENA ----------
typedef struct {
    char* data;
    size_t capacity;
    size_t offset;
} Arena;

void arena_init(Arena* a, size_t size) {
    a->data = (char*)malloc(size);
    a->capacity = size;
    a->offset = 0;
}

void* arena_alloc(Arena* a, size_t size) {
    if (a->offset + size > a->capacity) {
        // fallback (в реальной системе — лучше resize)
        return NULL;
    }
    void* ptr = a->data + a->offset;
    a->offset += size;
    return ptr;
}
// дублирование строки
char* arena_strdup(Arena* a, const char* s) {
    size_t len = strlen(s) + 1;
    char* dst = (char*)arena_alloc(a, len);
    memcpy(dst, s, len);
    return dst;
}

// ---------- HASH ----------
typedef struct CacheEntry {
    char* prefix;                  // строка в arena
    Word results[TOP_K];
    int top_size;
    struct CacheEntry* next;       // для chaining
} CacheEntry;

// простой и быстрый hash (djb2)
unsigned long hash_str(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

// ---------- СРАВНЕНИЯ ----------

int cmp_words(const void* a, const void* b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

int cmp_result(const void* a, const void* b) {
    Word* w1 = (Word*)a;
    Word* w2 = (Word*)b;

    if (w1->freq != w2->freq)
        return w2->freq - w1->freq;

    return strcmp(w1->word, w2->word);
}

// ---------- УТИЛИТЫ ----------

int starts_with(const char* word, const char* prefix) {
    return strncmp(word, prefix, strlen(prefix)) == 0;
}

int lower_bound(Word* words, int n, const char* prefix) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (strcmp(words[mid].word, prefix) < 0)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// ---------- TOP-K ----------
void add_to_top(Word* top, int* size, Word candidate) {
    if (*size < TOP_K) {
        top[*size] = candidate;
        (*size)++;
    } else {
        int worst = 0;
        for (int i = 1; i < *size; i++) {
            if (
                    top[i].freq < top[worst].freq 
                    ||
                    (
                        top[i].freq == top[worst].freq
                        &&
                        strcmp(top[i].word, top[worst].word) > 0
                    )
                ) {
                worst = i;
            }
        }

        if (
                candidate.freq > top[worst].freq
                ||
                (
                    candidate.freq == top[worst].freq
                    &&
                    strcmp(candidate.word, top[worst].word) < 0
                )
            ) {
            top[worst] = candidate;
        }
    }
}

// ---------- HASH TABLE ----------

CacheEntry* table[HASH_SIZE];

CacheEntry* cache_get(const char* prefix) {
    unsigned long h = hash_str(prefix) % HASH_SIZE;
    CacheEntry* cur = table[h];

    while (cur) {
        if (strcmp(cur->prefix, prefix) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void cache_put(Arena* arena, const char* prefix, Word* results, int top_size) {
    unsigned long h = hash_str(prefix) % HASH_SIZE;

    CacheEntry* entry = (CacheEntry*)arena_alloc(arena, sizeof(CacheEntry));
    entry->prefix = arena_strdup(arena, prefix);
    entry->top_size = top_size;

    for (int i = 0; i < top_size; i++) {
        entry->results[i] = results[i];
    }

    entry->next = table[h];
    table[h] = entry;
}

// ---------- MAIN ----------

int main() {

    // arena (примерный размер)
    Arena arena; // 
    arena_init(&arena, 63 * 1024 * 1024); // 63MB

    int N;
    scanf("%d", &N);

    Word* words = (Word*)arena_alloc(&arena, N * sizeof(Word));

    for (int i = 0; i < N; i++) {
        scanf("%s %d", words[i].word, &words[i].freq);
    }

    qsort(words, N, sizeof(Word), cmp_words);

    int M;
    scanf("%d", &M);

    char prefix[MAX_WORD_LEN];

    for (int qi = 0; qi < M; qi++) {
        if (qi > 0) printf("\n");

        scanf("%s", prefix);

        // ---------- ПРОВЕРКА в кэше ----------
        CacheEntry* cached = cache_get(prefix);
        if (cached) {
            for (int i = 0; i < cached->top_size; i++) {
                printf("%s\n", cached->results[i].word);
            }
            continue;
        }

        // ---------- ВЫЧИСЛЕНИЕ ----------
        int start = lower_bound(words, N, prefix);

        Word top[TOP_K];
        int top_size = 0;

        for (int i = start; i < N; i++) {
            if (!starts_with(words[i].word, prefix))
                break;

            add_to_top(top, &top_size, words[i]);
        }

        qsort(top, top_size, sizeof(Word), cmp_result);

        // ---------- СОХРАНЕНИЕ В КЕШ ----------
        cache_put(&arena, prefix, top, top_size);

        // ---------- ВЫВОД ----------
        for (int i = 0; i < top_size; i++) {
            printf("%s\n", top[i].word);
        }
    }

    free(arena.data);

    mem_statistics();

    return 0;
}
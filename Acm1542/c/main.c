#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 16
#define TOP 10

typedef struct {
    char *word;
    int freq;
} Word;

// компаратор для qsort
int cmp_words(const void *a, const void *b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

// сравниваем сначала по частотам, потом по алфавиту
int cmp_top(const void *a, const void *b) {
    Word *wa = (Word*)a;
    Word *wb = (Word*)b;
    if (wa->freq != wb->freq)
        return wb->freq - wa->freq;
    return strcmp(wa->word, wb->word);
}

// двоичный поиск - lower bound
// находим первое вхождение искомого символа (или индекс где он мог быть при отсутствии символа)
int lower_bound(Word *arr, int n, const char *prefix) {
    int l = 0, r = n; // левый и правый указатели
    while (l < r) { // пока левый меньше правого
        int m = (l + r) / 2; // середина
        if (strcmp(arr[m].word, prefix) < 0) 
            l = m + 1; // двигаем окно вправо
        else
            r = m; // двигаем окно влево
    }
    return l;
}

int starts_with(const char *word, const char *prefix) {
    while (*prefix) { // пока префикс не закончился \0
        if (*word++ != *prefix++) // сравниваем текущие символы, двигаем указатели       
            return 0; // если не равны - возвращаем 0
    }
    return 1; // равны - единицу
}

int main() {
    int N; scanf("%d", &N); // количество слов

    Word *words = malloc(sizeof(Word) * N);

    // Один общий буфер
    size_t buffer_size = (size_t)N * MAX_WORD_LEN;
    char *buffer = malloc(buffer_size);
    char *ptr = buffer;

    for (int i = 0; i < N; i++) {
        scanf("%s %d", ptr, &words[i].freq);
        words[i].word = ptr;
        ptr += strlen(ptr) + 1;
    }

    qsort(words, N, sizeof(Word), cmp_words);

    int M;
    scanf("%d", &M); // количество запросов

    char query[MAX_WORD_LEN];
    int first = 1;

    while (M--) {

        scanf("%s", query);

        if (!first) printf("\n"); else first = 0;

        int start = lower_bound(words, N, query);

        Word top[TOP] = {0,};
        int count = 0;

        for (int i = start; i < N && starts_with(words[i].word, query); i++) {

            if (count < TOP) {
                top[count++] = words[i];
                if (count == TOP)
                    qsort(top, count, sizeof(Word), cmp_top);
            } else {
                if (words[i].freq > top[TOP-1].freq ||
                   (words[i].freq == top[TOP-1].freq &&
                    strcmp(words[i].word, top[TOP-1].word) < 0)) {

                    top[TOP-1] = words[i];
                    qsort(top, TOP, sizeof(Word), cmp_top);
                }
            }
        }

        for (int i = 0; i < count; i++)
            printf("%s\n", top[i].word);
    }

    return 0;
}
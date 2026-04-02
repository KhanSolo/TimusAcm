#ifndef PROFILER_H
#define PROFILER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOCS 4096  // максимум блоков одновременно

static size_t total_allocated = 0;
static size_t total_freed     = 0;

static void* ptrs[MAX_ALLOCS]  = {0};
static size_t sizes[MAX_ALLOCS] = {0};
static int num_allocs = 0;

void* my_malloc(size_t size) {
    if (num_allocs >= MAX_ALLOCS) {
        fprintf(stderr, "Too many allocations!\n");
        return NULL;
    }

    void* p = malloc(size);
    if (!p) return NULL;

    ptrs[num_allocs]  = p;
    sizes[num_allocs] = size;
    num_allocs++;

    total_allocated += size;
    return p;
}

void my_free(void* p) {
    if (!p) return;

    // ищем указатель в таблице
    for (int i = 0; i < num_allocs; i++) {
        if (ptrs[i] == p) {
            total_freed += sizes[i];

            // удаляем, сдвигая хвост
            num_allocs--;
            if (i < num_allocs) {
                ptrs[i]  = ptrs[num_allocs];
                sizes[i] = sizes[num_allocs];
            }
            ptrs[num_allocs]  = NULL;
            sizes[num_allocs] = 0;

            free(p);
            return;
        }
    }

    fprintf(stderr, "my_free: unknown pointer %p\n", p);
    // обычно free(NULL) не делает ничего, но можно и так:
    // free(p);
}

#define malloc(size) my_malloc(size)
#define free(p)      my_free(p)

void mem_statistics(){
    printf("Всего выделено: %zu байт\n", total_allocated);
    printf("Количество аллокаций: %d\n", num_allocs);
    printf("Всего освобождено: %zu байт\n", total_freed);
    printf("Осталось в памяти (неосвобождённое): %zu байт\n", total_allocated - total_freed);
}

#endif // PROFILER_H
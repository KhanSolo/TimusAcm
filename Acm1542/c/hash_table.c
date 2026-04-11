#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_LEN 997

typedef struct ht {
    const char * key;
    char * value;
    struct ht * next;
} ht;

ht * hash_table[HASH_LEN];

unsigned long djb2(const char * str) {
    unsigned long hash = 5381;
    char c;
    while((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

ht* ht_new_entry(const char* key, char* value){
    ht* current = (ht*)malloc(sizeof(ht));
    current->key = key;
    current->value = value;
    current->next = NULL;
    return current;
}


void ht_add(const char* key, char* value){
    unsigned long hash = djb2(key);
    int bucket = hash % HASH_LEN;    
    ht* existing = hash_table[bucket];
    if (existing) {
        while (existing) {
            if (strcmp(existing->key, key) == 0) { // ключи равны 
                existing->value = value; // заменяем
                return;
            }
            if (!existing->next) {
                ht* current = ht_new_entry(key, value);
                existing->next = current;
                return;
            }
            existing = existing->next;
        }
    } else {
        ht* current = ht_new_entry(key, value);
        hash_table[bucket] = current;
    }
}

char* ht_get(const char* key){
    unsigned long hash = djb2(key);
    int bucket = hash % HASH_LEN;

    ht* existing = hash_table[bucket];
    if (existing) {
        while (existing) {
            if(0 == strcmp(existing->key, key)){ // ключи равны            
                return existing->value; 
            }
            existing = existing->next;
        }
    }
    return NULL;
}

void ht_print_value(const char* key) {
    char* val = ht_get(key);
    printf("for %s: [%s]\n", key, val ? val : "NULL");
}

void ht_init() {
    // глобальная ht будет заполнена нулями
    // если перенести в локальные переменные, то нужно заполнять
    memset(hash_table, 0, sizeof(hash_table));
}

int main(void) 
{
    ht_init();

    ht_add("num1", "Hello!");
    ht_add("num2", "World!");

    ht_print_value("num2");
    ht_print_value("num3");

    ht_add("num2", "Test!");

    ht_print_value("num2");

    return 0;
}
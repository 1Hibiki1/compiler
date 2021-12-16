#ifndef _VECTOR_H_
#define _VECTOR_H

#include <stdlib.h>
#include <stdint.h>

typedef void* item;
typedef struct {
    item* items;
    size_t max_len;
    size_t size;
} vector;
typedef vector* vector_t;

vector_t vector_new();
size_t vector_len(vector_t);
int vector_set(vector_t, size_t, item);
item vector_get(vector_t, size_t);
int vector_push(vector_t, item);
item vector_pop(vector_t);
void vector_free(vector_t, void (*free_fun)(item));

#endif

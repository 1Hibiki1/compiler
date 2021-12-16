#include "vector.h"

// constants
const size_t MIN_LEN = 8;
const size_t INC_FACTOR = 2;

// private function prototypes
int expand(vector_t);

vector_t vector_new(){
    vector_t v = (vector_t)malloc(sizeof(vector));
    v->size = 0;
    v->max_len = MIN_LEN;
    v->items = (item*)malloc(sizeof(item)*MIN_LEN);
    return v;
}

size_t vector_len(vector_t vec){
    return vec->size;
}

int vector_set(vector_t vec, size_t idx, item obj){
    if(idx >= (vec->size)) return -1;
    vec->items[idx] = obj;
    return 0;
}

item vector_get(vector_t vec, size_t idx){
    return vec->items[idx];
}

int vector_push(vector_t vec, item obj){
    size_t cur_sz = vec->size;
    
    if(cur_sz >= vec->max_len) 
        if(expand(vec) < 0) return -1;

    vec->items[cur_sz] = obj;
    // TODO: check for overflow
    vec->size += 1;

    return 0;
}

item vector_pop(vector_t vec){
    if(vec->size <= 0) return NULL;
    
    // TODO: check for overflow
    item i = vec->items[(vec->size) - 1];
    vec->size -= 1;

    return i;
}


int expand(vector_t vec){
    //item* cur_arr = vec->items;
    size_t cur_len = vec->max_len;
    
    // TODO: check for overflow
    size_t new_len = cur_len*INC_FACTOR;

    //item* new_arr = realloc(vec->items, sizeof(item)*new_len);
    //vec->items = new_arr;
    vec->items = realloc(vec->items, sizeof(item)*new_len);
    if(vec->items == NULL) return -1;
    
    vec->max_len *= INC_FACTOR;

    return 0;
}

void vector_free(vector_t vec, void (*free_fun)(item)){
    item* it = vec->items;
    if(free_fun != NULL){
        size_t sz = vec->size;
        for(size_t i = 0; i < sz; i++) free_fun(it[i]);
    }
    
    free(it);
    free(vec);
}





#include "../minunit.h"
#include "../../src/util/generic/vector.c"

static char* test_vector_new(){
    vector_t v = vector_new();
    mu_assert("TEST FAILED: new vector's size is not 0", (v->size) == 0);
    mu_assert("TEST FAILED: new vector's max_len is not MIN_LEN", (v->max_len) == MIN_LEN);
    mu_assert("TEST FAILED: new vector's items is not malloc'd", (v->items) != NULL);
    return 0;
}

static char* test_vector_push(){
    vector_t v = vector_new();
    int i = 5;
    vector_push(v, &i);

    mu_assert("TEST FAILED: push did not increment size", v->size == 1);
    mu_assert("TEST FAILED: push did not add item", v->items[0] != NULL);
    mu_assert("TEST FAILED: push value does not match", *(int*)(v->items[0]) == 5);
    mu_assert("TEST FAILED: push changed max_len, shouldn't have", v->max_len == MIN_LEN);

    vector_push(v, &i);
    mu_assert("TEST FAILED: push did not increment size", v->size == 2);
    mu_assert("TEST FAILED: push changed max_len, shouldn't have", v->max_len == MIN_LEN);

    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);

    mu_assert("TEST FAILED: push set size incorrectly", v->size == 8);
    
    i = 11;
    vector_push(v, &i);
    mu_assert("TEST FAILED: push did not expand heap", v->max_len == MIN_LEN*INC_FACTOR);
    mu_assert("TEST FAILED: push - incorrect item", *(int*)(v->items[8]) == 11);

    return 0;
}

static char* test_vector_len(){
    return 0;
}

static char* test_vector_pop(){
    return 0;
}

static char* test_vector_free(){
    return 0;
}



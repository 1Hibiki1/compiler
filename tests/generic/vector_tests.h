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
    vector_t v = vector_new();
    int i = 5;
    vector_push(v, &i);

    mu_assert("TEST FAILED: length not incremented", v->size == 1);

    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);

    mu_assert("TEST FAILED: length not set correctly", v->size == 11);

    return 0;
}

static char* test_vector_pop(){
    vector_t v = vector_new();
    int i = 5;

    vector_push(v, &i);
    int* popped_item = vector_pop(v);

    mu_assert("TEST FAILED: pop did not set size correctly", v->size == 0);
    mu_assert("TEST FAILED: pop did not return popped element", (popped_item != NULL && (*popped_item) == 5));

    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);
    vector_push(v, &i);

    i = 11;
    popped_item = vector_pop(v);
    mu_assert("TEST FAILED: pop did not return popped element", (popped_item != NULL && (*popped_item) == 11));
    return 0;
}

static char* test_vector_free(){
    // TODO: better tests?

    int* i = malloc(sizeof(int));
    *i = 7;

    vector_t v = vector_new();
    vector_push(v, i);

    vector_free(v, free);
    return 0;
}



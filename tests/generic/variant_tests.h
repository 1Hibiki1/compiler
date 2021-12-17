#include "../minunit.h"
#include "../../src/util/generic/variant.c"

static char* test_variant_new(){
    printf("running test_variant_new...\n");
    int* p = (int*)malloc(sizeof(int));
    *p = 11;
    variant_t v = variant_new(p, VAR_INT);

    mu_assert("TEST FAILED: variant type not set correctly", (v->type) == VAR_INT);
    mu_assert("TEST FAILED: variant payload not set correctly", (v->payload) == p);
    mu_assert("TEST FAILED: variant payload not set correctly", *(int*)(v->payload) == 11);

    free(p);
    return 0;
}

static char* test_variant_get_type(){
    printf("running test_variant_get_type...\n");
    int* p = (int*)malloc(sizeof(int));
    *p = 11;
    variant_t v = variant_new(p, VAR_INT);

    mu_assert("TEST FAILED: variant_set_type", variant_get_type(v) == VAR_INT);

    free(p);
    return 0;
}

static char* test_variant_get_payload(){
    printf("running test_variant_get_payload...\n");
    int* p = (int*)malloc(sizeof(int));
    *p = 11;
    variant_t v = variant_new(p, VAR_INT);

    mu_assert("TEST FAILED: variant_set_payload", variant_get_payload(v) == p);

    free(p);
    return 0;
}

static char* test_variant_set_type(){
    printf("running test_variant_set_type...\n");
    int* p = (int*)malloc(sizeof(int));
    *p = 11;
    variant_t v = variant_new(p, VAR_NONE);
    variant_set_type(v, VAR_INT);

    mu_assert("TEST FAILED: variant_set_type", (v->type) == VAR_INT);

    free(p);
    return 0;
}

static char* test_variant_set_payload(){
    printf("running test_variant_set_payload...\n");
    int* p = (int*)malloc(sizeof(int));
    *p = 11;
    variant_t v = variant_new(NULL, VAR_NONE);
    variant_set_payload(v, p);

    mu_assert("TEST FAILED: variant_set_payload", (v->payload) == p);

    free(p);
    return 0;
}

// TODO: tests for variant_free?
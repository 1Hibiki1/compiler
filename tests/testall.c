#include <stdio.h>
#include "minunit.h"

#include "generic/vector_tests.h"
#include "generic/variant_tests.h"

size_t tests_run = 0;

static char* all_tests(){
    mu_run_test(test_vector_new);
    mu_run_test(test_vector_push);
    mu_run_test(test_vector_pop);
    mu_run_test(test_vector_len);
    mu_run_test(test_vector_free);
    printf("All tests for vector passed\n\n");

    mu_run_test(test_variant_new);
    mu_run_test(test_variant_get_type);
    mu_run_test(test_variant_get_payload);
    mu_run_test(test_variant_set_type);
    mu_run_test(test_variant_set_payload);
    printf("All tests for variant passed\n\n");

    return 0;
}

int main(){
    char *result = all_tests();
    if (result != 0) {
       printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %zu\n", tests_run);

    return result != 0;
}


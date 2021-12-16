#include <stdio.h>
#include "minunit.h"

#include "generic/vector_tests.h"

size_t tests_run = 0;

/*static char* test_vector_new(){
    vector_t v = vector_new();
    mu_assert("TEST FAILED: vector_new returned NULL", v != NULL);
    return 0;
}*/

static char* all_tests(){
    mu_run_test(test_vector_new);
    mu_run_test(test_vector_push);
    mu_run_test(test_vector_pop);
    mu_run_test(test_vector_len);
    mu_run_test(test_vector_free);
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
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}


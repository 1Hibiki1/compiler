#include <stdio.h>
#include "util/generic/vector.h"

int main(){
    int x = 5;
    vector_t v = vector_new();
    vector_push(v, &x);
    vector_push(v, &x);
    vector_push(v, &x);
    vector_push(v, &x);
    vector_push(v, &x);
    vector_push(v, &x);
    vector_push(v, &x);
    vector_push(v, &x);
    vector_push(v, &x);
    
    for(size_t i = 0; i < vector_len(v); ++i)
        printf("%d,", *(int*)vector_get(v, i));
    printf("\n");
        
    vector_pop(v);
    vector_pop(v);
    vector_pop(v);
    vector_pop(v);
    vector_pop(v);
    vector_pop(v);
    vector_pop(v);
    vector_pop(v);
    vector_pop(v);

    vector_free(v, NULL);
    printf("Hello!\n");
    return 0;
}

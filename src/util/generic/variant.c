#include "variant.h"
#include <stdlib.h>

variant_t variant_new(void* payload, _VAR_TYPE type){
    // TODO: check for out of mem
    variant_t v = (variant_t)malloc(sizeof(variant));
    v->payload = payload;
    v->type = type;
    return v;
}

_VAR_TYPE variant_get_type(variant_t v){
    return v->type;
}

void* variant_get_payload(variant_t v){
    return v->payload;
}

void variant_set_type(variant_t v, _VAR_TYPE t){
    v->type = t;
}

void variant_set_payload(variant_t v, void* payload){
    v->payload = payload;
}

void variant_free(variant_t v, void (*free_function)(void*)){
    free_function(v->payload);
    free(v);
}
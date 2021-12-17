#ifndef _VARIANT_H_
#define _VARIANT_H_

/* types */
typedef enum {
    VAR_NONE,
    VAR_INT,
    VAR_STRING
} _VAR_TYPE;

typedef struct {
    void* payload;
    _VAR_TYPE type;
} variant;

typedef variant* variant_t;


/* functions */
variant_t variant_new(void* payload, _VAR_TYPE type);
_VAR_TYPE variant_get_type(variant_t);
void* variant_get_payload(variant_t);
void variant_set_type(variant_t, _VAR_TYPE);
void variant_set_payload(variant_t, void* payload);
void variant_free(variant_t, void (*free_function)(void*));

#endif
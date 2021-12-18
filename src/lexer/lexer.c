#include "lexer.h"
#include <ctype.h>
#include <stdbool.h>

// lexer state struct
typedef struct {
    size_t cur_pos;
    char cur_ch;
    bool error;
} __ls;
typedef __ls* __LS;


// private function prototypes
void identifier(__LS, char*, vector_t);


// function definitions
token_t token_new(){
    token_t t = (token_t)malloc(sizeof(token));
    t->type = TOK_NONE;
    t->value = variant_new(NULL, VAR_NONE);
    return t;
}

bool is_id_nondigit(char x){
    return isalpha(x) || (x == '_');
}

vector_t lexer_tokenize(char* inp){
    if(inp == NULL) return NULL;  // TODO: return empty vector?

    vector_t output = vector_new();

    //__LS state = (__LS)malloc(sizeof(__ls));
    __ls state;
    state.cur_pos = 0;
    state.cur_ch = inp[0];
    state.error = false;
    __LS _state = &state;

    if (state.cur_ch == '\0') return output;

    else if (is_id_nondigit(state.cur_ch)){
        identifier(_state, inp, output);
    }

    //free(state);
    return output;
}


void identifier(__LS state, char* inp, vector_t output){
    token_t tok = token_new();
    tok->type = TOK_IDENTIFIER;

    char* id = malloc(__MAX_ID_LENGTH);
    size_t cur_pos = 0;

    while (is_id_nondigit(state->cur_ch)) {
        // TODO: check for overflow (id len > 64)
        id[cur_pos] = state->cur_ch;
        state->cur_ch = inp[state->cur_pos];

        cur_pos++;
        state->cur_pos++;
    }

    variant_set_type(tok->value, VAR_STRING);
    variant_set_payload(tok->value, (void*)id);

    vector_push(output, tok);    
}

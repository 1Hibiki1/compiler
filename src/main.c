#include <stdio.h>
#include "lexer/lexer.h"

int main(){
    vector_t token_list = lexer_tokenize("hello happy world");
    return 0;
}

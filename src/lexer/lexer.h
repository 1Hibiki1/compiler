#ifndef _LEXER_H_
#define _LEXER_H_

#include "../util/generic/vector.h"
#include "token.h"

#define __MAX_ID_LENGTH 64

vector_t lexer_tokenize(char*);

#endif
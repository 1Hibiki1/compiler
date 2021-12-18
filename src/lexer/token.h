#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "../util/generic/variant.h"

// TODO: add preprocessing tokens (C18, A.1.1 (6.4))
typedef enum {
    TOK_NONE,

    // keywords
    TOK_AUTO,
    TOK_EXTERN,
    TOK_BREAK,
    TOK_FLOAT,
    TOK_CASE,
    TOK_FOR,
    TOK_CHAR,
    TOK_GOTO,
    TOK_CONST,
    TOK_IF,
    TOK_CONTINUE,
    TOK_INLINE,
    TOK_DEFAULT,
    TOK_INT,
    TOK_DO,
    TOK_LONG,
    TOK_DOUBLE,
    TOK_REGISTER,
    TOK_ELSE,
    TOK_RESTRICT,
    TOK_ENUM,
    TOK_RETURN,
    TOK_SHORT,
    TOK_SIGNED,
    TOK_SIZEOF,
    TOK_STATIC,
    TOK_STRUCT,
    TOK_SWITCH,
    TOK_TYPEDEF,
    TOK_UNION,
    TOK_UNSIGNED,
    TOK_VOID,
    TOK_VOLATILE,
    TOK_WHILE,
    TOK__ALIGNAS,
    TOK__ALIGNOF,
    TOK__ATOMIC,
    TOK__BOOL,
    TOK__COMPLEX,
    TOK__GENERIC,
    TOK__IMAGINARY,
    TOK__NORETURN,
    TOK__STATIC_ASSERT,
    TOK__THREAD_LOCAL,
    

    TOK_IDENTIFIER,

    // constants
    TOK_INT_CONST,
    TOK_FLOAT_CONST,
    TOK_ENUM_CONST,
    TOK_CHAR_CONST,

    TOK_STR_LITERAL,
    TOK_PUNCTUATOR,
} TOK_TYPE;

typedef struct {
    variant_t value;
    TOK_TYPE type;
} token;

typedef token* token_t;

#endif
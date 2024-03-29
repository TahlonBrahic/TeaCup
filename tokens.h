#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Tokens
typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_EOF,  // End of File token
    TOKEN_INVALID
} TokenType;

typedef struct {
    TokenType type;
    int value; // Used for TOKEN_INT
} Token;

int lexer(Token *t);static int scanint(int c);
int next(void);
void putback(int c);
int skip(void);
int chrpos(char *s, int c);
##include <stdio.h>

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_STAR,
    TOKEN_EOF,  // End of File token
    TOKEN_INVALID
} TokenType;

typedef struct {
    TokenType type;
    int value; // Used for TOKEN_INT
} Token;

int main() {
    return 0;
}

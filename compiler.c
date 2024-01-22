 ##include <stdio.h>

// Tokens
typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_EOF,  // End of File token
    TOKEN_INVALID:
} TokenType;

typedef struct {
    TokenType type;
    int value; // Used for TOKEN_INT
} Token;

// Lexer Functions


// Retrieves the next character from the input file.
static int next(void) {
  int c;

  if (Putback) {
    c = Putback;
    Putback = 0;
    return c;
  }

  c = fgetc(file);
  if ('\n' == c) {
    Line++
  }

  return c;
}

void lexer(FILE *file){
    char current_token = fgetc(file)
}

// Parser


// Main
int main() {
    return 0;
}

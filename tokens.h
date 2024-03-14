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

// AST nodes
enum {
    A_ADD,
    A_SUBSTRACT,
    A_MULTIPLY,
    A_DIVIDE,
    A_INTLIT
};

// AST Structure
struct ASTnode {
    int op;
    struct ASTnode *left;
    struct ASTnode *right;
    int intvalue;
};

struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intvalue);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);
struct ASTnode *binexpr(void);
int interpretAST(struct ASTnode *n);

int lexer(Token *t);static int scanint(int c);
int next(void);
void putback(int c);
int skip(void);
int chrpos(char *s, int c);
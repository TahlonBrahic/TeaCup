#include data.h
#include tokens.h

static struct ASTnode *primary(void) {
    struct ASTnode *n;

    switch(Token.token) {
        case T_INTLIT:
            n=mkastleaf(A_INTLIT, Token.intvalue);
            lexer(&Token);
            return(n);
        default:
            fprintf(stderr, "syntax error on line %d\n");
            exit(1);
    }
}

int arithop(int tok) {
    switch (tok) {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE); 
        default:
            fprintf(stderr, "unknown token in arithop() on line %d\n", Line);
            exit(1);
    }
}
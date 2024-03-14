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
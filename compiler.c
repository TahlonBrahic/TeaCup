#include "tokens.h"
#define extern_
#include "data.h"
#undef extern_
#include <errno.h>

static void init() {
    Line = 1;
    Putback = '\n';
}

char *tokstr[] = { "+", "-", "*", "/", "intlit" };

static void scanfile() {
    struct Token T;
    while (scan(&T)) {
        printf("Token %s", tokstr[T.token]);
        if (T.token == T_INTLIT)
            printf(", value %d" T.intvalue);
        printf("\n");
    }
}

int main() {

    init();
    scanfile();
    exit(0);
};

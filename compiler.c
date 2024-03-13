#include "tokens.h"
#define extern_
#include "data.h"
#undef extern_
#include <errno.h>

// Reset state management
static void init() {
    Line = 1;
    Putback = '\n';
}

char *tokstr[] = { "int", "+", "-", "*", "/", "eof", "invalid" };

static void scanfile() {
    Token T;
    while (lexer(&T)) {
        printf("Token %s", tokstr[T.type]);
        if (T.type == TOKEN_INT)
            printf(", value %d", T.value);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    init();

    if ((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scanfile();
    exit(0);
};

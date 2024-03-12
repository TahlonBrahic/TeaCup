#include "tokens.h"
#include "data.h"

static int lexer(struct Token *t){
  int c;
  c = skip();
  switch (c) {
    case '+':
      t->token = TOKEN_PLUS;
    case '-':
      t->token = TOKEN_MINUS;
    case '*':
      t->token = TOKEN_STAR;
    case '/':
      t->token = TOKEN_SLASH;
    case EOF:
      return 0;
    default:
      if (isdigit(c)) {
        t->intvalue = scanint(c);
        t->token = TOKEN_INT;
        break;
      }
  };
  return 1;
};

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
    Line++;
  };

  return c;
};

static void putback(int c) {
  Putback = c;
}

// Skip past white space, newlines, ect...
static int skip(void) {
  int c;

  c = next();
  while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
    c = next();
  }
  return (c);
}
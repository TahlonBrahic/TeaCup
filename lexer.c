#include "tokens.h"
#include "data.h"

int lexer(Token *t){
  int c;
  c = skip();
  switch (c) {
    case '+':
      t->type = TOKEN_PLUS;
      break;
    case '-':
      t->type = TOKEN_MINUS;
      break;
    case '*':
      t->type = TOKEN_STAR;
      break;
    case '/':
      t->type = TOKEN_SLASH;
      break;
    case EOF:
      t->type = TOKEN_EOF;
      return 0;
    default:
      if (isdigit(c)) {
        t->value = scanint(c);
        t->type = TOKEN_INT;
        break;
      }
  };
  return 1;
};

static int scanint(int c) {
  int k, val = 0;

  // Convert each character into an integer
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 +k;
    c = next();
  }

  // Non-intenger characters
  putback(c);
  return val;
}

static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}

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

// Allows the lexer to 'un-read' a character by storing it in the putback.
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
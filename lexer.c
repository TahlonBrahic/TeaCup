#include "tokens.h"
#include "data.h"

static int lexer(struct Token *t){
  int c;
  
  switch (c) {
    case EOF:
      return 0;
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

static int skip(void) {
  int c;

  c = next();
  while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
    c = next();
  }
  return (c);
}
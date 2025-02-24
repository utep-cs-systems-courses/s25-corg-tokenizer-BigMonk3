#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() 
{
  char c;
  char str[100];

  printf("Type any string to be tokenized, -h for help\n");

  while (1) { // Infinite while loop

    printf("$ ");
    if ((c = getchar()) == '\n') continue;
    ungetc(c,stdin); 
    fgets(str, 100, stdin);
    char **tokens = tokenize(str);

    switch(c) {
      case ('!'):
        break;
      case ('-'):
        break;
      default:
        print_tokens(tokens);
        free_tokens(tokens);
    }

  }
}

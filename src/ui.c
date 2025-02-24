#include <stdio.h>
#include <string.h> // for strcmp()
#include "tokenizer.h"
#include "history.h"

int main() 
{
  char c;
  char str[100];
  int f;

  printf("Type any string to be tokenized, -h for help\n");

  while (1) { // Infinite while loop

    printf("$ ");
    if ((c = getchar()) == '\n') continue;
    ungetc(c,stdin); 
    fgets(str, 100, stdin);
    char **tokens = tokenize(str);

    if (!strcmp(*tokens, "-h"))
    {
      f = 1;
    } else if (!strcmp(*tokens, "history"))
    {
      f = 2;
    } else if (**tokens == '!')
    {
      f = 3;
    } else if (!strcmp(*tokens, "-t"))
    {
      f = 4;
    } else if (!strcmp(*tokens, "exit")) return 0;
    else f = 0;

    switch(f) {
      case (1):
        printf("help:\n\t-h: this dialogue\n\t");
        printf("-t [string]: prints the tokenized [string]\n\t");
        printf("history: shows a history of inputs\n\t");
        printf("![index]: runs the input at [index] in history\n\t");
        printf("exit: quits the program\n");
        break;
      case (2):
        break;
      case (3):
        break;
      case (4):
        print_tokens(tokens+1);
        break;
      default:
        printf("\tinvalid command; -h for help\n");
    }
    free_tokens(tokens);
  }
}

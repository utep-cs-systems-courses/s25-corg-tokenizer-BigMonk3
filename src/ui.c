#include <stdlib.h>
#include <stdio.h>
#include <string.h> // for strcmp()
#include "tokenizer.h"
#include "history.h"

int main() 
{
  char c;
  char *str = malloc(100 * sizeof(char)); 
  int f;
  int done = 0;
  int id;
  List *history = init_history();

  printf("Type a command, '-h' for help\n");

  while (1) { // Infinite while loop

    printf("$ ");
    if ((c = getchar()) == '\n') continue;
    ungetc(c,stdin); 
    fgets(str, 100, stdin);
    char **tokens = tokenize(str);

    add_history(history, str);

    do {
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
      } else if (!strcmp(*tokens, "exit")) {
        free_tokens(tokens);
        free_history(history);
        free(str);
        return 0;
      } else f = -1;

      switch(f) {
        case (1):
          printf("help:\n\t-h: this dialogue\n\t");
          printf("-t [string]: prints the tokenized [string]\n\t");
          printf("history: shows a history of inputs\n\t");
          printf("![id]: runs the input at [index] in history\n\t");
          printf("exit: quits the program\n");
          done = 1;
          break;
        case (2):
          print_history(history -> root);
          done = 1;
          break;
        case (3):
          if (strlen(*tokens) > 1 && **tokens == '!') {
            id = atoi(*tokens + 1); // Extract ID from the first token
          } else {
            printf("ERROR: Invalid format. Use '![id]'\n");
            done = 1;
            break;
          }
          str = get_history(history, id);
          if (str) {
            free_tokens(tokens);
            tokens = tokenize(str);
            done = 0;
          } else {
            printf("ERROR: Invalid history id\n");
            done = 1;
          }
          break;
        case (4):
          print_tokens(tokens);
          done = 1;
          break;
        default:
          printf("ERROR: invalid command; -h for help\n");
          done = 1;
      } 
    } while (!done);
  }
}

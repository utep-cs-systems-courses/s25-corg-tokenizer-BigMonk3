#include <stdio.h>

int main() 
{
  while (1) { // Infinite while loop

    fputs("[]$ ",stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    
    char c;
    if ((c = getchar()) == '\n') continue;
    ungetc(c,stdin);
    while ((c = getchar()) != '\n') { 
      putchar(c);
    }
    putchar('\n');
  }
}

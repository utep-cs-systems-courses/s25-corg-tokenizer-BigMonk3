#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c) 
{
  return (c == '\t' || c == ' ' || c == '\n' || c == 0); // newline included
}

int non_space_char(char c)
{
  return (c && !space_char(c));
}

char *token_start(char *str)
{
  int i = 0;
  while (*(str+i))
  {
    if (non_space_char(*(str+i))) return str+i;
    i++;
  }
  return str+i;
}

char *token_terminator(char *token)
{
  int i = 0;
  while (*(token+i))
  {
    if (space_char(*(token+i))) return token+i;
    i++;
  }
  return token+i;
}

int count_tokens(char *str)
{
  int count = 0;
  char *temp = str;

  temp = token_start(temp);
  while (*temp) //while current char is not EOF
  {
    count = non_space_char(*temp) ? count+1 : count;
    temp = token_terminator(temp);
    temp = token_start(temp);
  }
  return count;
}   

char *copy_str(char *inStr, short len)
{
  char *outStr = malloc(len+1);
  int i = 0;
  while (i < len)
  {
    *(outStr+i) = *(inStr+i);
    i++;
  } 
  *(outStr+i) = 0;

  return outStr;
}

char **tokenize(char *str)
{
  int size = count_tokens(str);
  char **tokens = malloc((size+1)*sizeof(char*));
  char **temp = tokens;

  str = token_start(str);
  while (*str)
  {
    char *end = token_terminator(str);
    int wordSize = end - str;
    *temp = copy_str(str, wordSize);
    str = end;
    str = token_start(str);
    *temp++;
  }
  *temp = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  for (int t = 1; *(tokens+t); t++) // from 1 to exclude '-t' without misrepresenting indices
  {
    printf("[%d] %s\n", t, *(tokens+t));
  }
}

void free_tokens(char **tokens) 
{
  int i = 0;
  do
  {
    free (*(tokens+i));
    i++;
  } while (*(tokens+i));
  free (tokens);
}

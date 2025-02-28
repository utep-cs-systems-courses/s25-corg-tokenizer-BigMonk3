#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen()
#include "history.h"
#include "tokenizer.h"

List *init_history() {
  List *list = malloc(sizeof(List));
  list -> root = NULL;
  return list;
}

// add item to the history list
// root is the most recent item
// list is linked back to 1
void add_history(List *list, char *str) {
  Item *item = malloc(sizeof(Item));
  if (!(list -> root)) {
    item -> id = 1;
    item -> next = NULL; 
  } else {
    item -> id = list -> root -> id + 1;
    item -> next = list -> root;
  }
  item -> str = copy_str(str, strlen(str)+1); 
  list -> root = item;
}

char *get_history(List *list, int id) {
  Item *root = list -> root;
  while (root) {
    if (root -> id == id) {
      return root -> str;
    }
    root = root -> next;
  }
  return 0;
}

void print_history(Item *root) {
  if(root) {
    print_history(root -> next);
    printf("[%d] %s", root -> id, root -> str);
  }
  return;
}

void free_history(List *list) {
  Item *current = list->root;
  while (current != NULL) {
    Item *next = current->next;
    free(current->str); // Free the string
    free(current);
    current = next;
  }
  free(list);
} 

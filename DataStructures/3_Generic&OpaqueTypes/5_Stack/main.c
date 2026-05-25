#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  char command[10];
  Stack *q = stack_construct();

  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    if (strcmp(command, "PUSH") == 0) {
      char *val = (char *)malloc(100 * sizeof(char));
      scanf("%s\n", val);
      stack_push(q, val);
    } else if (strcmp(command, "POP") == 0) {
      char *val = (char *)stack_pop(q);
      printf("%s\n", val);
      free(val);
    }
  }

  for (int i = 0; i < stack_size(q); i++) {
    free(stack_pop(q));
  }
  stack_destruct(q);
  return 0;
}

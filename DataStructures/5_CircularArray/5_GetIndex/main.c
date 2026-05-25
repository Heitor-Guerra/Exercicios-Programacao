#include "deque.h"
#include <stdio.h>
#include <string.h>

int main() {
  Deque *deque = deque_construct();
  int ops;
  scanf("%d", &ops);

  for (int i = 0; i < ops; i++) {
    char command[15];
    scanf("\n%s", command);
    if (strcmp(command, "PUSH_BACK") == 0) {
      int j;
      scanf("%d", &j);
      deque_push_back(deque, j);
    } else if (strcmp(command, "PUSH_FRONT") == 0) {
      int j;
      scanf("%d", &j);
      deque_push_front(deque, j);
    } else if (strcmp(command, "POP_BACK") == 0) {
      int j = deque_pop_back(deque);
      printf("%d\n", j);
    } else if (strcmp(command, "POP_FRONT") == 0) {
      int j = deque_pop_front(deque);
      printf("%d\n", j);
    } else if (strcmp(command, "GET") == 0) {
      int j;
      scanf("%d", &j);
      printf("%d\n", deque_get(deque, j));
    }
  }

  deque_destroy(deque);
  return 0;
}

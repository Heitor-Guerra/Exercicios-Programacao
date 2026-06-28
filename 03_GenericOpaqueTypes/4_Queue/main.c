#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  char command[10];
  Queue *q = queue_construct();

  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    if (strcmp(command, "ENQUEUE") == 0 || strcmp(command, "ENQUEUE ") == 0) {
      char *val = (char *)malloc(100 * sizeof(char));
      scanf("%s\n", val);
      queue_enqueue(q, val);
    } else if (strcmp(command, "DEQUEUE") == 0 ||
               strcmp(command, "DEQUEUE ") == 0) {
      char *val = (char *)queue_dequeue(q);
      printf("%s\n", val);
      free(val);
    }
  }

  for (int i = 0; i < queue_size(q); i++) {
    free(queue_dequeue(q));
  }
  queue_destroy(q);
  return 0;
}

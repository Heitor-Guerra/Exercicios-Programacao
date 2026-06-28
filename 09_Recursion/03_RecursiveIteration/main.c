#include "forward_list.h"
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  ForwardList *l = forward_list_construct();

  for (int i = 0; i < n; i++) {
    int a;
    scanf("\n%d", &a);

    forward_list_push_front(l, a);
  }

  forward_list_print(l);

  forward_list_destroy(l);
  return 0;
}

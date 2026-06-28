#include <stdio.h>

void recursiveFor(int start, int end, int step) {
  if (start == end) {
    return;
  }
  printf("%d\n", start);
  recursiveFor(start + step, end, step);
}

int main() {
  int start, end, step;

  scanf("%d %d %d", &start, &end, &step);

  recursiveFor(start, end, step);

  return 0;
}

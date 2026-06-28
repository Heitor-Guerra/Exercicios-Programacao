#include <stdio.h>

int recursiveExp(int base, int exp) {
  if (exp == 0) {
    return 1;
  }

  return base * recursiveExp(base, exp - 1);
}

int main() {
  int base, exp;

  scanf("%d %d", &base, &exp);

  printf("%d", recursiveExp(base, exp));

  return 0;
}

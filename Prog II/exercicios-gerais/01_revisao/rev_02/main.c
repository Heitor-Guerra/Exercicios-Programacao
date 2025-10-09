#include <stdio.h>

int main() {
  int num = 1, i, j, linhas;
  scanf("%d", &linhas);

  for (i = 1; i <= linhas; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", num);
      num++;
    }
    printf("\n");
  }

  return 0;
}

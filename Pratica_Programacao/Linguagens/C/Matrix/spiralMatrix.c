#include <stdio.h>

struct spiral_t {
  int size;
  int matrix[10][10];
} spiral;

int main() {
  int size = 6;
  spiral.size = size;
  int num = 1;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      spiral.matrix[i][j] = 0;
    }
  }

  for (int i = 0; i < size / 2 + 1; i++) {
    for (int j = i; j < size - i; j++) {
      if (spiral.matrix[i][j] == 0) {
        spiral.matrix[i][j] = num;
        num++;
      }
    }
    for (int j = i + 1; j < size - i; j++) {
      if (spiral.matrix[j][size - 1 - i] == 0) {
        spiral.matrix[j][size - 1 - i] = num;
        num++;
      }
    }
    for (int j = size - 2; j >= i; j--) {
      if (spiral.matrix[size - 1 - i][j] == 0) {
        spiral.matrix[size - 1 - i][j] = num;
        num++;
      }
    }
    for (int j = size - 2; j >= i + 1; j--) {
      if (spiral.matrix[j][i] == 0) {
        spiral.matrix[j][i] = num;
        num++;
      }
    }
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", spiral.matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}

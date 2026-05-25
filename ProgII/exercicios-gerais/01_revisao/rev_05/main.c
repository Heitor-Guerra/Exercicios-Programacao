#include <stdio.h>

#define NUM_MOVIMENTOS_POSSIVEIS 4

void leMapa(int linhas, int colunas, int mapa[linhas][colunas]) {
  int i, j;
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      scanf("%d", &mapa[i][j]);
    }
  }
}

int main() {
  int linhas, colunas, i, impossivel = 0;
  scanf("%d %d", &linhas, &colunas);
  int mapa[linhas][colunas];
  leMapa(linhas, colunas, mapa);

  int xi, yi, xf, yf;
  char ordemMovimentos[NUM_MOVIMENTOS_POSSIVEIS];
  scanf("%d %d %d %d\n", &yi, &xi, &yf, &xf);
  xi--;
  yi--;
  xf--;
  yf--;
  for (i = 0; i < NUM_MOVIMENTOS_POSSIVEIS; i++) {
    scanf("%c", &ordemMovimentos[i]);
  }

  while (!impossivel) {
    if (xi == xf && yi == yf) {
      break;
    }
    printf("(%d,%d) ", yi + 1, xi + 1);
    mapa[yi][xi] = 1;
    impossivel = 1;
    for (i = 0; i < NUM_MOVIMENTOS_POSSIVEIS; i++) {
      if (ordemMovimentos[i] == 'B' && mapa[yi + 1][xi] == 0 &&
          yi != linhas - 1) {
        yi++;
        impossivel = 0;
        break;
      } else if (ordemMovimentos[i] == 'C' && mapa[yi - 1][xi] == 0 &&
                 yi != 0) {
        yi--;
        impossivel = 0;
        break;
      } else if (ordemMovimentos[i] == 'D' && mapa[yi][xi + 1] == 0 &&
                 xi != colunas - 1) {
        xi++;
        impossivel = 0;
        break;
      } else if (ordemMovimentos[i] == 'E' && mapa[yi][xi - 1] == 0 &&
                 xi != 0) {
        xi--;
        impossivel = 0;
        break;
      }
    }
  }
  printf("(%d,%d) ", yi + 1, xi + 1);
  return 0;
}

#include "matrizgenerica.h"
#include "numcomplexo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lin, col, tipo, escolha;
  tMatrizGenerica *matrix;
inicio:
  tipo = -1;
  printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, "
         "1 – float, 2 – double, 3 – char, 4 – número complexo):\n");
  do {
    scanf("%d %d %d\n", &lin, &col, &tipo);
  } while (tipo < 0 || tipo > 4);

  switch (tipo) {
  case 0: {
    matrix = CriaMatrizGenerica(lin, col, sizeof(int));
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        int num;
        scanf("%d", &num);
        AtribuiElementoMatrizGenerica(matrix, i, j, &num);
      }
      scanf("\n");
    }
    break;
  }
  case 1: {
    matrix = CriaMatrizGenerica(lin, col, sizeof(float));
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        float num;
        scanf("%f", &num);
        AtribuiElementoMatrizGenerica(matrix, i, j, &num);
      }
      scanf("\n");
    }
    break;
  }
  case 2: {
    matrix = CriaMatrizGenerica(lin, col, sizeof(double));
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        double num;
        scanf("%lf", &num);
        AtribuiElementoMatrizGenerica(matrix, i, j, &num);
      }
      scanf("\n");
    }
    break;
  }
  case 3: {
    matrix = CriaMatrizGenerica(lin, col, sizeof(char));
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        char num;
        scanf("%c", &num);
        scanf("%*c");
        AtribuiElementoMatrizGenerica(matrix, i, j, &num);
      }
    }
    break;
  }
  case 4: {
    matrix = CriaMatrizGenerica(lin, col, RetornaNumBytesComplexo());
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        float r, i;
        scanf("(%f,%f)", &r, &i);
        scanf("%*c");
        tNumComplexo *num = CriaNumComplexo(r, i);
        AtribuiElementoMatrizGenerica(matrix, i, j, num);
      }
    }
    break;
  }
  }

  printf("Digite a operação desejada\n");
  printf("1 - Apenas imprimir a matriz\n");
  printf("2 - Converter para o tipo complexo e imprimir\n");
  printf("3 - Calcular e imprimir a multiplicacao da matriz pela sua "
         "transposta.\n");
  scanf("%d\n", &escolha);
  switch (escolha) {
  case 1: {
    ImprimirMatrizGenerica break;
  }
  case 2: {
    break;
  }
  case 3: {
    break;
  }
  }

  return 0;
}

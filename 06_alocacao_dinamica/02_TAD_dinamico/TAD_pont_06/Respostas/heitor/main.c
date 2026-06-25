#include "matrix_utils.h"
#include <stdio.h>

int main() {
  int rows, cols;

  scanf("%d %d", &rows, &cols);
  tMatrix *matrix1 = MatrixCreate(rows, cols);
  MatrixRead(matrix1);

  scanf("%d %d", &rows, &cols);
  tMatrix *matrix2 = MatrixCreate(rows, cols);
  MatrixRead(matrix2);

  int choice = 0;
  do {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");

    printf("Opcao escolhida: \n");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      if (!PossibleMatrixSum(matrix1, matrix2)) {
        printf("Erro: as dimensoes da matriz nao correspondem\n");
        break;
      }
      tMatrix *res = MatrixAdd(matrix1, matrix2);
      MatrixPrint(res);
      MatrixFree(res);
      break;
    }
    case 2: {
      if (!PossibleMatrixSub(matrix1, matrix2)) {
        printf("Erro: as dimensoes da matriz nao correspondem\n");
        break;
      }
      tMatrix *res = MatrixSub(matrix1, matrix2);
      MatrixPrint(res);
      MatrixFree(res);
      break;
    }
    case 3: {
      if (!PossibleMatrixMultiply(matrix1, matrix2)) {
        printf("Erro: o numero de colunas da primeira matriz eh diferente do "
               "numero de linhas da segunda matriz\n");
        break;
      }
      tMatrix *res = MatrixMultiply(matrix1, matrix2);
      MatrixPrint(res);
      MatrixFree(res);
      break;
    }
    case 4: {
      int scalar, matrixToMultiply;
      scanf("%d %d", &scalar, &matrixToMultiply);
      tMatrix *res;
      switch (matrixToMultiply) {
      case 1:
        res = MatrixMultiplyByScalar(matrix1, scalar);
        MatrixFree(matrix1);
        matrix1 = res;
        MatrixPrint(matrix1);
        break;
      case 2:
        res = MatrixMultiplyByScalar(matrix2, scalar);
        MatrixFree(matrix2);
        matrix2 = res;
        MatrixPrint(matrix2);
        break;
      }
      break;
    }
    case 5: {
      tMatrix *res1 = TransposeMatrix(matrix1);
      MatrixPrint(res1);
      MatrixFree(res1);

      tMatrix *res2 = TransposeMatrix(matrix2);
      MatrixPrint(res2);
      MatrixFree(res2);
      break;
    }
    }

  } while (choice != 6);

  MatrixFree(matrix1);
  MatrixFree(matrix2);

  return 0;
}

#include "matrix_utils.h"
#include <stdio.h>

void process_choice(tMatrix *matrix1, tMatrix *matrix2, int choice) {

  switch (choice) {
  case 1:
    if (!PossibleMatrixSum(*matrix1, *matrix2)) {
      printf("Erro: as dimensoes da matriz nao correspondem\n");
      return;
    }
    MatrixPrint(MatrixAdd(*matrix1, *matrix2));
    return;
  case 2:
    if (!PossibleMatrixSub(*matrix1, *matrix2)) {
      printf("Erro: as dimensoes da matriz nao correspondem\n");
      return;
    }
    MatrixPrint(MatrixSub(*matrix1, *matrix2));
    return;
  case 3:
    if (!PossibleMatrixMultiply(*matrix1, *matrix2)) {
      printf("Erro: o numero de colunas da primeira matriz eh diferente do "
             "numero de linhas da segunda matriz\n");
      return;
    }
    MatrixPrint(MatrixMultiply(*matrix1, *matrix2));
    return;
  case 4: {
    int scalar, matrixToMultiply;
    scanf("%d %d", &scalar, &matrixToMultiply);
    switch (matrixToMultiply) {
    case 1:
      *matrix1 = MatrixMultiplyByScalar(*matrix1, scalar);
      MatrixPrint(*matrix1);
      return;
    case 2:
      *matrix2 = MatrixMultiplyByScalar(*matrix2, scalar);
      MatrixPrint(*matrix2);
      return;
    }
    return;
  }
  case 5:
    MatrixPrint(TransposeMatrix(*matrix1));
    MatrixPrint(TransposeMatrix(*matrix2));
    return;
  }
}

int main() {
  int rows, cols;

  scanf("%d %d", &rows, &cols);
  tMatrix matrix1 = MatrixCreate(rows, cols);
  matrix1 = MatrixRead(matrix1);

  scanf("%d %d", &rows, &cols);
  tMatrix matrix2 = MatrixCreate(rows, cols);
  matrix2 = MatrixRead(matrix2);

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
    process_choice(&matrix1, &matrix2, choice);
  } while (choice != 6);

  return 0;
}

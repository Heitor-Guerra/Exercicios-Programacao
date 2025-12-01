#include "matrix_utils.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado. Alocar
 * dinamicamente o espaço na memória para a matriz bidimensional
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix *MatrixCreate(int rows, int cols) {
  tMatrix *matrix = (tMatrix *)malloc(sizeof(tMatrix));
  matrix->rows = rows;
  matrix->cols = cols;

  matrix->data = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = (int *)malloc(cols * sizeof(int));
  }
  return matrix;
}

/**
 * @brief Libera toda a memória alocada por uma matriz
 * @param matrix O ponteiro para a estrutura que armazena uma matriz.
 */
void MatrixFree(tMatrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 */
void MatrixRead(tMatrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      scanf("%d", &matrix->data[i][j]);
    }
  }
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    printf("|");
    for (int j = 0; j < matrix->cols; j++) {
      if (j == matrix->cols - 1) {
        printf("%d", matrix->data[i][j]);
      } else {
        printf("%d ", matrix->data[i][j]);
      }
    }
    printf("|\n");
  }
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix *matrix1, tMatrix *matrix2) {
  return matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix *matrix1, tMatrix *matrix2) {
  return matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix *matrix1, tMatrix *matrix2) {
  return matrix1->cols == matrix2->rows;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix *MatrixAdd(tMatrix *matrix1, tMatrix *matrix2) {
  tMatrix *res = MatrixCreate(matrix1->rows, matrix1->cols);

  for (int i = 0; i < res->rows; i++) {
    for (int j = 0; j < res->cols; j++) {
      res->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
    }
  }
  return res;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix *MatrixSub(tMatrix *matrix1, tMatrix *matrix2) {
  tMatrix *res = MatrixCreate(matrix1->rows, matrix1->cols);

  for (int i = 0; i < res->rows; i++) {
    for (int j = 0; j < res->cols; j++) {
      res->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
    }
  }
  return res;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix *MatrixMultiply(tMatrix *matrix1, tMatrix *matrix2) {
  tMatrix *res = MatrixCreate(matrix1->rows, matrix2->cols);

  for (int i = 0; i < res->rows; i++) {
    for (int j = 0; j < res->cols; j++) {
      int sum = 0;
      for (int k = 0; k < matrix1->cols; k++) {
        sum += matrix1->data[i][k] * matrix2->data[k][j];
      }
      res->data[i][j] = sum;
    }
  }

  return res;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix *TransposeMatrix(tMatrix *matrix) {
  tMatrix *res = MatrixCreate(matrix->cols, matrix->rows);

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      res->data[j][i] = matrix->data[i][j];
    }
  }
  return res;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix *MatrixMultiplyByScalar(tMatrix *matrix, int scalar) {
  tMatrix *res = MatrixCreate(matrix->rows, matrix->cols);

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      res->data[i][j] = scalar * matrix->data[i][j];
    }
  }
  return res;
}

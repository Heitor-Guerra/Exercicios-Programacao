#include <stdio.h>

void readMatrix(short int order, short int matrix[order][order]) {
  for (short int i = 0; i < order; i++) {
    for (short int j = 0; j < order; j++) {
      scanf("%hd", &matrix[i][j]);
    }
  }
}

void printMatrix(short int order, short int matrix[order][order]) {
  for (short int i = 0; i < order; i++) {
    printf("| ");
    for (short int j = 0; j < order; j++) {
      printf("%05d ", matrix[i][j]);
    }
    printf("|\n");
  }
}

short int getLineWithMostZeros(short int order,
                               short int matrix[order][order]) {
  short int maxZeros = 0, currentZeros = 0, maxZerosIndex = 0;
  for (short int i = 0; i < order; i++) {
    currentZeros = 0;
    for (short int j = 0; j < order; j++) {
      if (matrix[i][j] == 0) {
        currentZeros++;
      }
    }
    if (currentZeros > maxZeros) {
      maxZeros = currentZeros;
      maxZerosIndex = i;
    }
  }
  return maxZerosIndex;
}

void getCofactor(short int order, short int matrix[order][order],
                 short int line, short int col,
                 short int cofactor[order - 1][order - 1]) {
  int cofactorI = 0, cofactorJ = 0;

  for (short int i = 0; i < order; i++) {
    if (i == line)
      continue;

    cofactorJ = 0;
    for (short int j = 0; j < order; j++) {
      if (j == col)
        continue;

      cofactor[cofactorI][cofactorJ] = matrix[i][j];
      cofactorJ++;
    }
    cofactorI++;
  }
}

int getDeterminant(short int order, short int matrix[order][order]) {
  int determinant = 0;
  short int lineToUse = getLineWithMostZeros(order, matrix);
  if (order == 1) {
    return matrix[0][0];
  }
  for (short int j = 0; j < order; j++) {
    if (matrix[lineToUse][j] == 0) {
      continue;
    }
    short int cofactor[order - 1][order - 1];
    getCofactor(order, matrix, lineToUse, j, cofactor);
    switch ((lineToUse + j) % 2) {
    case 0:
      determinant += matrix[lineToUse][j] * getDeterminant(order - 1, cofactor);
      break;
    case 1:
      determinant -= matrix[lineToUse][j] * getDeterminant(order - 1, cofactor);
    }
  }
  return determinant;
}

int main() {
  short int order;
  puts("Give a number to the order of the square matrix: ");
  scanf("%hd", &order);
  while (order < 1) {
    puts("Give a valid number (>= 1)");
    scanf("%hd", &order);
  }

  short int matrix[order][order];
  puts("\n\nWrite down your matrix\n");
  readMatrix(order, matrix);

  puts("\n\nThis is your matrix\n");
  printMatrix(order, matrix);
  puts("\n\n");

  printf("The determinant of your matrix is: %d",
         getDeterminant(order, matrix));

  return 0;
}

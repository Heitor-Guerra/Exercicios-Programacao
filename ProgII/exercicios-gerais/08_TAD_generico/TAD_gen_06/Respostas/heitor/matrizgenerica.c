#include "matrizgenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adaptado do código compartilhado pelo prof. Thiago

typedef void *DataType;

struct matrizgenerica {
  DataType **dados;
  int linhas, colunas;
  int byteE;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz
 * de qualquer tipo de dados, desde que esse tipo ocupe determinado número de
 * bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem) {
  tMatrizGenerica *m = (tMatrizGenerica *)malloc(sizeof(tMatrizGenerica));
  m->linhas = linhas;
  m->colunas = colunas;
  m->byteE = numByteElem;

  m->dados = (DataType **)malloc(linhas * sizeof(DataType *));
  for (int i = 0; i < linhas; i++) {
    m->dados[i] = (DataType *)malloc(colunas * sizeof(DataType));
    for (int j = 0; j < colunas; j++) {
      m->dados[i][j] = (DataType)malloc(numByteElem);
    }
  }

  return m;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica *mat) {
  for (int i = 0; i < mat->linhas; i++) {
    for (int j = 0; j < mat->colunas; j++) {
      free(mat->dados[i][j]);
    }
    free(mat->dados[i]);
  }
  free(mat->dados);
  free(mat);
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat) {
  return mat->linhas;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat) {
  return mat->colunas;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na
 * linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna
 * passadas como parâmetro
 */
void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna) {
  return mat->dados[linha][coluna];
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha
 * e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será
 * feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna
 * passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna,
                                   void *elem) {
  memcpy(mat->dados[linha][coluna], elem, mat->byteE);
}
/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados
 * da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha
 * e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a
 * capacidade de imprimir os dados de um elemento desta matriz
 */

void ImprimirMatrizGenerica(tMatrizGenerica *mat,
                            void(imprime_elemento(void *))) {
  for (int i = 0; i < mat->linhas; i++) {
    for (int j = 0; j < mat->colunas; j++) {
      imprime_elemento(mat->dados[i][j]);
      printf(" ");
    }
    printf("\n");
  }
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat) {
  tMatrizGenerica *t =
      CriaMatrizGenerica(mat->colunas, mat->linhas, mat->byteE);

  for (int i = 0; i < t->linhas; i++) {
    for (int j = 0; j < t->colunas; j++) {
      memcpy(t->dados[i][j], mat->dados[j][i], mat->byteE);
    }
  }

  return t;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante
 * @param multi_elem - Ponteiro para função (callback) que realiza a
 * multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre
 * dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e
 * mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1,
                                    tMatrizGenerica *mat2, int numByteTarget,
                                    void *(*multi_elem)(void *, void *),
                                    void *(*soma_elem)(void *, void *)) {
  tMatrizGenerica *t =
      CriaMatrizGenerica(mat1->linhas, mat2->colunas, numByteTarget);

  for (int i = 0; i < t->linhas; i++) {
    for (int j = 0; j < t->colunas; j++) {
      free(t->dados[i][j]);
      DataType temp0 = multi_elem(mat1->dados[i][0], mat2->dados[0][j]);
      for (int k = 1; k < mat1->colunas; k++) {
        DataType temp1 = multi_elem(mat1->dados[i][k], mat2->dados[k][j]);
        DataType temp2 = soma_elem(temp0, temp1);
        free(temp0);
        free(temp1);
        temp0 = temp2;
      }
      t->dados[i][j] = temp0;
    }
  }

  return t;
}

/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter
 * o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem,
                                    void *(*converte_elem)(void *)) {
  tMatrizGenerica *t =
      CriaMatrizGenerica(mat2->linhas, mat2->colunas, novoNumByteElem);

  for (int i = 0; i < t->linhas; i++) {
    for (int j = 0; j < t->colunas; j++) {
      free(t->dados[i][j]);
      t->dados[i][j] = converte_elem(mat2->dados[i][j]);
    }
  }
  return t;
}

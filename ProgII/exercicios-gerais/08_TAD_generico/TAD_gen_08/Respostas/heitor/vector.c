#include "vector.h"
#include <stdlib.h>

struct Vector {
  DataType *data;
  int num;
};

/**
 * @brief Cria um vetor vazio
 *
 * @return A estrutura Vector inicializada. Caso não seja possível alocar
 * memória, o programa é encerrado.
 */
Vector *VectorConstruct() {
  Vector *vec = (Vector *)malloc(sizeof(Vector));
  vec->num = 0;
  vec->data = NULL;
  return vec;
}

/**
 * @brief Adiciona um elemento no final do vetor
 *
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
 */
void VectorPushBack(Vector *v, DataType val) {
  v->data = (DataType *)realloc(v->data, (v->num + 1) * sizeof(DataType));
  v->data[v->num] = val;
  v->num++;
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou
 * seja, o segundo elemento passa a ser o primeiro, o terceiro passa a ser o
 * segundo, e assim por diante.
 *
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
 */
DataType VectorPopFront(Vector *v) {
  DataType rem = v->data[0];
  for (int i = 0; i < v->num - 1; i++) {
    v->data[i] = v->data[i + 1];
  }
  v->num--;
  return rem;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 *
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
 */
DataType VectorGet(Vector *v, int i) { return v->data[i]; }

/**
 * @brief Retorna o tamanho do vetor
 *
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
 */
int VectorSize(Vector *v) { return v->num; }

/**
 * @brief Libera a memória alocada para o vetor
 *
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do
 * vetor
 */
void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
  for (int i = 0; i < v->num; i++) {
    destroy(v->data[i]);
  }
  if (v->data != NULL) {
    free(v->data);
  }
  free(v);
}

#include "vector.h"
#include <stdlib.h>

#define TAM_INCREMENTO_VECTOR 3

struct Vector {
  DataType *data;
  int num;
  int numAloc;
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
  vec->numAloc = TAM_INCREMENTO_VECTOR;
  vec->data = (DataType *)malloc(vec->numAloc * sizeof(DataType));
  return vec;
}

/**
 * @brief Adiciona um elemento no final do vetor
 *
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
 */
void VectorPushBack(Vector *v, DataType val) {
  if (v->num >= v->numAloc) {
    v->numAloc += TAM_INCREMENTO_VECTOR;
    v->data = (DataType *)realloc(v->data, v->numAloc * sizeof(DataType));
  }
  v->data[v->num] = val;
  v->num++;
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
  free(v->data);
  free(v);
}

#include "array.h"
#include <stdio.h>
#include <stdlib.h>

struct Array {
  int tamanho;
  int *numeros;
};

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja
 * possível alocar memória.
 */
Array *CriarArray() {
  Array *arr = (Array *)malloc(sizeof(Array));
  arr->numeros = NULL;
  arr->tamanho = 0;

  return arr;
}

/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array) {
  if (array->tamanho > 0) {
    free(array->numeros);
  }
  free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória
 * para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array) {
  int num;
  while (scanf("%d", &num) == 1) {
    array->numeros =
        (int *)realloc(array->numeros, (array->tamanho + 1) * sizeof(int));
    array->numeros[array->tamanho] = num;
    array->tamanho++;
  }
  scanf("%*[^\n]\n");
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array) {
  int pronto = 0;
  while (!pronto) {
    for (int i = 1; i < array->tamanho; i++) {
      if (array->numeros[i - 1] > array->numeros[i]) {
        int temp = array->numeros[i - 1];
        array->numeros[i - 1] = array->numeros[i];
        array->numeros[i] = temp;
      }
    }
    pronto = 1;
    for (int i = 1; i < array->tamanho; i++) {
      if (array->numeros[i - 1] > array->numeros[i]) {
        pronto = 0;
        break;
      }
    }
  }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado) {
  int limInf = 0, limSup = array->tamanho - 1;

  while (limInf < limSup) {
    int media = (limInf + limSup) / 2;
    if (array->numeros[media] == elementoBuscado) {
      return media;
    } else if (array->numeros[media] < elementoBuscado) {
      limInf = media + 1;
    } else if (array->numeros[media] > elementoBuscado) {
      limSup = media;
    }
  }

  return -1;
}

#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic {
  Type tipo;
  void *dados;
  int numElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto
 * inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem) {
  tGeneric *generic = (tGeneric *)malloc(sizeof(tGeneric));
  generic->tipo = type;
  generic->numElem = numElem;
  if (type == FLOAT) {
    generic->dados = malloc(numElem * sizeof(float));
  } else if (type == INT) {
    generic->dados = malloc(numElem * sizeof(int));
  }

  return generic;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen) {
  free(gen->dados);
  free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen) {
  printf("\nDigite o vetor:");
  for (int i = 0; i < gen->numElem; i++) {
    if (gen->tipo == INT) {
      scanf("%d ", (int *)gen->dados + i);
    } else if (gen->tipo == FLOAT) {
      scanf("%f ", (float *)gen->dados + i);
    }
  }
  scanf("\n");
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen) {
  printf("\n");
  for (int i = 0; i < gen->numElem; i++) {
    if (gen->tipo == INT) {
      printf("%d ", ((int *)gen->dados)[i]);
    } else if (gen->tipo == FLOAT) {
      printf("%.2f ", ((float *)gen->dados)[i]);
    }
  }
}

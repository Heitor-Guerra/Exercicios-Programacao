#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura representando um Movel.
 */
struct Movel {
  char nome[30];
};

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome) {
  tMovel *movel = (tMovel *)malloc(sizeof(tMovel));
  strcpy(movel->nome, nome);
  return movel;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m) { free(m); }

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel() {
  char nome[30];
  scanf("%s\n", nome);
  return CriaMovel(nome);
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m) { printf("%s\n", m->nome); }

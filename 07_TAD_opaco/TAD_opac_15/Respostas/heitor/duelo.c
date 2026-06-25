#include "duelo.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura de dados que representa um duelo entre duas cartas.
 */
struct duelo {
  int id;
  int c1;
  int c2;
  char atributo;

  int diff;
  bool desempate;
};

#define MAGIA 'M' /**< Opção para duelo de magia. */
#define FORCA 'F' /**< Opção para duelo de força. */
#define FOGO 'G'  /**< Opção para duelo de fogo. */

/**
 * @brief Lê um duelo do usuário.
 * @return Retorna um ponteiro para o duelo lido.
 */
tDuelo LeDuelo() {
  tDuelo duel = (tDuelo)malloc(sizeof(struct duelo));
  scanf("%d\n", &duel->id);
  scanf("%d %d %c\n", &duel->c1, &duel->c2, &duel->atributo);

  duel->diff = 0;
  duel->desempate = false;
  return duel;
}

/**
 * @brief Libera a memória alocada para um duelo.
 * @param d Ponteiro para o duelo a ser liberado.
 */
void LiberaDuelo(tDuelo d) { free(d); }

/**
 * @brief Imprime as informações de um duelo.
 * @param d Ponteiro para o duelo a ser impresso.
 */
void ImprimeDuelo(tDuelo d) {
  printf("Id: %d\n", d->id);
  printf("IdC1: %d\n", d->c1);
  printf("IdC2: %d\n", d->c2);
  printf("Atributo: %c\n", d->atributo);
}

/**
 * @brief Realiza um duelo entre duas cartas.
 * @param d Ponteiro para o duelo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 */
void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2) {

  switch (d->atributo) {
  case 'M':
    d->diff = ComparaMagiaCarta(c1, c2);
    break;
  case 'F':
    d->diff = ComparaAtaqueCarta(c1, c2);
    break;
  case 'G':
    d->diff = ComparaFogoCarta(c1, c2);
    break;
  }

  if (d->diff == 0) {
    d->desempate = true;
    if (ComparaIdCarta(c1, c2) > 0) {
      AdicionaVitoriaCarta(c2);
    } else {
      AdicionaVitoriaCarta(c1);
    }
  } else if (d->diff > 0) {
    AdicionaVitoriaCarta(c2);
  } else {
    AdicionaVitoriaCarta(c1);
  }
}

/**
 * @brief Retorna o ID da primeira carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da primeira carta do duelo.
 */
int GetC1Duelo(tDuelo d) { return d->c1; }

/**
 * @brief Retorna o ID da segunda carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da segunda carta do duelo.
 */
int GetC2Duelo(tDuelo d) { return d->c2; }

/**
 * @brief Retorna se houve desempate no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna true se houve desempate e false caso contrário.
 */
bool GetDesempateDuelo(tDuelo d) { return d->desempate; }

/**
 * @brief Retorna a diferença de pontos entre as cartas no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna a diferença de pontos entre as cartas no duelo.
 */
int GetDiferencaDuelo(tDuelo d) { return d->diff; }

/**
 * @brief Retorna o ID do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID do duelo.
 */
int GetIdDuelo(tDuelo d) { return d->id; }

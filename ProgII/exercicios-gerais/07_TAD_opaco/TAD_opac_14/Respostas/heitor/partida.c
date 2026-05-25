#include "partida.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 32

/**
 * @brief Constante que representa o time da casa.
 *
 */
#define TIME_CASA 1

/**
 * @brief Constante que representa o time visitante.
 *
 */
#define TIME_FORA 2

/**
 * @brief Estrutura que representa uma partida.
 *
 * A estrutura partida contém informações sobre os times que jogaram e o
 * vencedor da partida.
 *
 */
struct partida {
  char nomeCasa[MAX_NOME];
  char nomeVis[MAX_NOME];
  int ptosCasa;
  int ptosVis;
};

/**
 * @brief Lê uma partida do teclado.
 *
 * @return tPartida Retorna um ponteiro para a partida lida.
 */
tPartida LePartida() {
  tPartida partida = (tPartida)malloc(sizeof(struct partida));

  scanf("%s @ %s %d %d\n", partida->nomeCasa, partida->nomeVis,
        &partida->ptosCasa, &partida->ptosVis);

  return partida;
}

/**
 * @brief Libera a memória alocada para uma partida.
 *
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida p) { free(p); }

/**
 * @brief Imprime as informações de uma partida.
 *
 * @param p Ponteiro para a partida a ser impressa.
 */
void ImprimePartida(tPartida p) {
  printf("CASA: %s\n", p->nomeCasa);
  printf("VISITANTE: %s\n", p->nomeVis);
  printf("PLACAR: %d:%d\n", p->ptosCasa, p->ptosVis);
  printf("VENCEDOR: %d\n", GetVencedorPartida(p));
}

/**
 * @brief Retorna o nome do time da casa.
 *
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time da casa.
 */
char *GetTime1Partida(tPartida p) { return p->nomeCasa; }

/**
 * @brief Retorna o nome do time visitante.
 *
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time visitante.
 */
char *GetTime2Partida(tPartida p) { return p->nomeVis; }

/**
 * @brief Retorna o vencedor da partida.
 *
 * @param p Ponteiro para a partida.
 * @return int Retorna a constante que representa o vencedor da partida
 * (TIME_CASA ou TIME_FORA).
 */
int GetVencedorPartida(tPartida p) {
  if (p->ptosCasa > p->ptosVis) {
    return TIME_CASA;
  }
  return TIME_FORA;
}

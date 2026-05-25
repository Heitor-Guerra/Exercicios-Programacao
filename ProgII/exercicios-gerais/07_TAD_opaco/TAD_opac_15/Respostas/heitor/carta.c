#include "carta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carta {
  int id;
  char nome[MAX_NOME];
  int magia;
  int forca;
  int fogo;

  int vitorias;
};

/**
 * @brief Lê uma carta do usuário e retorna um ponteiro para ela.
 * @return Retorna um ponteiro para a carta lida.
 */
tCarta LeCarta() {
  tCarta carta = (tCarta)malloc(sizeof(struct carta));
  scanf("%d\n", &carta->id);
  scanf("%[^\n]\n", carta->nome);
  scanf("%d %d %d\n", &carta->magia, &carta->forca, &carta->fogo);

  carta->vitorias = 0;

  return carta;
}

/**
 * @brief Libera a memória alocada para uma carta.
 * @param c Ponteiro para a carta a ser liberada.
 */
void LiberaCarta(tCarta c) { free(c); }

/**
 * @brief Imprime as informações de uma carta.
 * @param c Ponteiro para a carta a ser impressa.
 */
void ImprimeCarta(tCarta c) {
  printf("Nome: %s\n", c->nome);
  printf("Id: %d\n", c->id);
  printf("Magia: %d\n", c->magia);
  printf("Forca: %d\n", c->forca);
  printf("Fogo: %d\n", c->fogo);
  printf("Vitorias: %d\n", c->vitorias);
}

/**
 * @brief Retorna o ID de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o ID da carta.
 */
int GetIdCarta(tCarta c) { return c->id; }

/**
 * @brief Retorna o nome de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o nome da carta.
 */
char *GetNomeCarta(tCarta c) { return c->nome; }

/**
 * @brief Retorna o número de vitórias de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o número de vitórias da carta.
 */
int GetNumVitCarta(tCarta c) { return c->vitorias; }

/**
 * @brief Retorna o valor de magia de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de magia da carta.
 */
int GetMagiaCarta(tCarta c) { return c->magia; }

/**
 * @brief Retorna o valor de ataque de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de ataque da carta.
 */
int GetAtaqueCarta(tCarta c) { return c->forca; }

/**
 * @brief Retorna o valor de fogo de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de fogo da carta.
 */
int GetFogoCarta(tCarta c) { return c->fogo; }

/**
 * @brief Verifica se uma carta é válida.
 * @param c Ponteiro para a carta.
 * @return Retorna true se a carta é válida e false caso contrário.
 */
bool EhCartaValida(tCarta c) {
  return c->magia <= 30 && c->forca <= 30 && c->fogo <= 30 &&
         (c->magia + c->forca + c->fogo <= 80) && strlen(c->nome) <= 50;
}

/**
 * @brief Verifica se duas cartas possuem o mesmo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna true se as cartas possuem o mesmo ID e false caso contrário.
 */
bool EhMesmoIdCarta(tCarta c1, tCarta c2) { return c1->id == c2->id; }

/**
 * @brief Compara duas cartas pelo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor
 * positivo se c1 > c2.
 */
int ComparaIdCarta(tCarta c1, tCarta c2) { return c2->id - c1->id; }

/**
 * @brief Compara duas cartas pelo valor de magia.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor
 * positivo se c1 > c2.
 */
int ComparaMagiaCarta(tCarta c1, tCarta c2) { return c2->magia - c1->magia; }

/**
 * @brief Compara duas cartas pelo valor de ataque.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor
 * positivo se c1 > c2.
 */
int ComparaAtaqueCarta(tCarta c1, tCarta c2) { return c2->forca - c1->forca; }

/**
 * @brief Compara duas cartas pelo valor de fogo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor
 * positivo se c1 > c2.
 */
int ComparaFogoCarta(tCarta c1, tCarta c2) { return c2->fogo - c1->fogo; }

/**
 * @brief Adiciona uma vitória para uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o novo número de vitórias da carta.
 */
int AdicionaVitoriaCarta(tCarta c) { return c->vitorias++; }

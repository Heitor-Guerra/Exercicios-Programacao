#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

#define PECA_1_SIMBOLO 'X'
#define PECA_2_SIMBOLO '0'
#define PECA_VAZIA_SIMBOLO '-'

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro() {
  tTabuleiro *tab = (tTabuleiro *)malloc(sizeof(tTabuleiro));
  tab->peca1 = PECA_1_SIMBOLO;
  tab->peca2 = PECA_2_SIMBOLO;
  tab->pecaVazio = PECA_VAZIA_SIMBOLO;
  tab->posicoes = (char **)malloc(TAM_TABULEIRO * sizeof(char *));
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    tab->posicoes[i] = (char *)malloc(TAM_TABULEIRO * sizeof(char));
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      tab->posicoes[i][j] = tab->pecaVazio;
    }
  }
  return tab;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    free(tabuleiro->posicoes[i]);
  }
  free(tabuleiro->posicoes);
  free(tabuleiro);
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y) {
  switch (peca) {
  case PECA_1:
    tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    break;
  case PECA_2:
    tabuleiro->posicoes[y][x] = tabuleiro->peca2;
    break;
  }
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      if (tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio) {
        return 1;
      }
    }
  }
  return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y,
                                    int peca) {
  switch (peca) {
  case PECA_1:
    return tabuleiro->posicoes[y][x] == tabuleiro->peca1;
  case PECA_2:
    return tabuleiro->posicoes[y][x] == tabuleiro->peca2;
  default:
    return 0;
  }
}

/**
 * Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y) {
  return tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 *
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y) {
  return x < TAM_TABULEIRO && x >= 0 && y < TAM_TABULEIRO && y >= 0;
}

/**
 * Imprime o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    printf("\t");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      printf("%c", tabuleiro->posicoes[i][j]);
    }
    printf("\n");
  }
}

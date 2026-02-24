#include "tabuleiro.h"
#include <stdio.h>

#define PECA_1_SIMBOLO 'X'
#define PECA_2_SIMBOLO '0'
#define PECA_VAZIO_SIMBOLO '-'

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 *
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro() {
  tTabuleiro tab;
  tab.peca1 = PECA_1_SIMBOLO;
  tab.peca2 = PECA_2_SIMBOLO;
  tab.pecaVazio = PECA_VAZIO_SIMBOLO;
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      tab.posicoes[i][j] = tab.pecaVazio;
    }
  }
  return tab;
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 *
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
  switch (peca) {
  case PECA_1:
    tabuleiro.posicoes[y][x] = PECA_1_SIMBOLO;
    break;
  case PECA_2:
    tabuleiro.posicoes[y][x] = PECA_2_SIMBOLO;
    break;
  }
  return tabuleiro;
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      if (tabuleiro.posicoes[i][j] == PECA_VAZIO_SIMBOLO) {
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
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y,
                                    int peca) {
  return ((peca == PECA_1 && tabuleiro.posicoes[y][x] == PECA_1_SIMBOLO) ||
          (peca == PECA_2 && tabuleiro.posicoes[y][x] == PECA_2_SIMBOLO));
}

/**
 * Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 *
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
  return tabuleiro.posicoes[y][x] == PECA_VAZIO_SIMBOLO;
}
/**
 * Verifica se a posição do tabuleiro é válida.
 *
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y) {
  return x >= 0 && x <= 2 && y >= 0 && y <= 2;
}

/**
 * Verifica se o tabuleiro está cheio.
 *
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro) {
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    printf("\t");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      printf("%c", tabuleiro.posicoes[i][j]);
    }
    printf("\n");
  }
}

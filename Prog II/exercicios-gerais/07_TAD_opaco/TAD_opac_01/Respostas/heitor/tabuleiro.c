#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

#define PECA_1_SIMBOLO 'X'
#define PECA_2_SIMBOLO '0'
#define PECA_VAZIA_SIMBOLO '-'

struct Tabuleiro {
  int grid[TAM_TABULEIRO][TAM_TABULEIRO];
};

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro() {
  tTabuleiro *tab = (tTabuleiro *)malloc(sizeof(tTabuleiro));

  for (int i = 0; i < TAM_TABULEIRO; i++) {
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      tab->grid[i][j] = 0;
    }
  }

  return tab;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro) { free(tabuleiro); }

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y) {
  tabuleiro->grid[y][x] = peca;
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
      if (tabuleiro->grid[i][j] == 0) {
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
  return tabuleiro->grid[y][x] == peca;
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
  return tabuleiro->grid[y][x] == 0;
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
  return x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO;
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
      switch (tabuleiro->grid[i][j]) {
      case 0:
        printf("%c", PECA_VAZIA_SIMBOLO);
        break;
      case 1:
        printf("%c", PECA_1_SIMBOLO);
        break;
      case 2:
        printf("%c", PECA_2_SIMBOLO);
        break;
      }
    }
    printf("\n");
  }
}

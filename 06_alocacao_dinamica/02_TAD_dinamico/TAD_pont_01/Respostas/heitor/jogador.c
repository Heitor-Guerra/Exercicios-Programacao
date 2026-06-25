#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 *
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador *CriaJogador(int idJogador) {
  tJogador *jogador = (tJogador *)malloc(sizeof(tJogador));
  jogador->id = idJogador;
  return jogador;
}

/**
 * Libera a memória de uma estrutura do tipo tJogador.
 *
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador *jogador) { free(jogador); }

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
  tJogada *jogada = CriaJogada();
  int x, y;
  while (1) {
    printf("Jogador %d\n", jogador->id);
    LeJogada(jogada);
    if (!FoiJogadaBemSucedida(jogada)) {
      continue;
    }
    x = ObtemJogadaX(jogada);
    y = ObtemJogadaY(jogada);

    if (!EhPosicaoValidaTabuleiro(x, y)) {
      printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
      continue;
    }
    if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
      printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
      continue;
    }
    break;
  }
  printf("Jogada [%d,%d]!\n", x, y);
  MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
  DestroiJogada(jogada);
}

/**
 * Verifica se o jogador venceu o jogo.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
  int venceuColuna = 0, venceuLinha = 0, venceuDiag1 = 1, venceuDiag2 = 1;

  for (int i = 0; i < TAM_TABULEIRO; i++) {
    if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador->id)) {
      venceuDiag1 = 0;
    }
    if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, TAM_TABULEIRO - i - 1, i,
                                         jogador->id)) {
      venceuDiag2 = 0;
    }

    venceuColuna = 1, venceuLinha = 1;
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador->id)) {
        venceuLinha = 0;
      }
      if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador->id)) {
        venceuColuna = 0;
      }
    }
    if (venceuLinha || venceuColuna) {
      return 1;
    }
  }
  if (venceuDiag1 || venceuDiag2) {
    return 1;
  }
  return 0;
}

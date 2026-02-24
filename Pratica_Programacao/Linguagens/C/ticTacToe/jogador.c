#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 *
 * @param idJogador o id do jogador (1 ou 2).
 *
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador) {
  tJogador jogador = {idJogador};
  return jogador;
}

/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do
 * jogador.
 *
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
  tJogada jogada = {0};
  int ocupada = 1, fora = 1, x = 0, y = 0;
  while (1) {
    printf("Jogador %d\n", jogador.id);
    jogada = LeJogada();
    if (!FoiJogadaBemSucedida(jogada)) {
      continue;
    }
    x = ObtemJogadaX(jogada);
    y = ObtemJogadaY(jogada);
    ocupada = !EstaLivrePosicaoTabuleiro(tabuleiro, x, y);
    fora = !EhPosicaoValidaTabuleiro(x, y);

    if (fora) {
      printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
      continue;
    } else if (ocupada) {
      printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
      continue;
    }
    break;
  }

  printf("Jogada [%d,%d]!\n", x, y);
  int peca = 0;
  if (jogador.id == ID_JOGADOR_1) {
    peca = PECA_1;
  } else if (jogador.id == ID_JOGADOR_2) {
    peca = PECA_2;
  }
  tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);
  return tabuleiro;
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso
 * contrário.
 *
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
  int venceuLinha, venceuColuna, venceuDiagonal1 = 1, venceuDiagonal2 = 1;
  for (int i = 0; i < TAM_TABULEIRO; i++) {
    if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador.id)) {
      venceuDiagonal1 = 0;
    }
    if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, TAM_TABULEIRO - 1 - i, i,
                                         jogador.id)) {
      venceuDiagonal2 = 0;
    }
    venceuLinha = 1;
    venceuColuna = 1;
    for (int j = 0; j < TAM_TABULEIRO; j++) {
      if (!EstaMarcadaPosicaoPecaTabuleiro(
              tabuleiro, j, i, jogador.id)) { // Verifica se venceu na linha
        venceuLinha = 0;
      }
      if (!EstaMarcadaPosicaoPecaTabuleiro(
              tabuleiro, i, j,
              jogador.id)) { // Verifica se venceu na coluna;
        venceuColuna = 0;
      }
    }
    if (venceuLinha || venceuColuna) {
      return 1;
    }
  }
  if (venceuDiagonal1 || venceuDiagonal2) {
    return 1;
  }
  return 0;
}

#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogo {
  tTabuleiro *tab;
  tJogador *jog1;
  tJogador *jog2;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo *CriaJogo() {
  tJogo *jogo = (tJogo *)malloc(sizeof(tJogo));
  if (!jogo) {
    exit(1);
  }
  jogo->tab = CriaTabuleiro();
  jogo->jog1 = CriaJogador(ID_JOGADOR_1);
  jogo->jog2 = CriaJogador(ID_JOGADOR_2);

  return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo *jogo) {
  while (!AcabouJogo(jogo)) {
    JogaJogador(jogo->jog1, jogo->tab);
    ImprimeTabuleiro(jogo->tab);
    if (VenceuJogador(jogo->jog1, jogo->tab)) {
      printf("JOGADOR 1 Venceu!\n");
      return;
    }

    if (AcabouJogo(jogo)) {
      break;
    }

    JogaJogador(jogo->jog2, jogo->tab);
    ImprimeTabuleiro(jogo->tab);
    if (VenceuJogador(jogo->jog2, jogo->tab)) {
      printf("JOGADOR 2 Venceu!\n");
      return;
    }
  }
  printf("Sem vencedor!\n");
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo *jogo) { return !TemPosicaoLivreTabuleiro(jogo->tab); }

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
  char escolha;
  printf("Jogar novamente? (s,n)\n");
  scanf("%*[^sn]%c", &escolha);
  return escolha == 's';
}

/**
 * Libera a memória de uma estrutura do tipo tJogo.
 *
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo *jogo) {
  DestroiJogador(jogo->jog1);
  DestroiJogador(jogo->jog2);
  DestroiTabuleiro(jogo->tab);
  free(jogo);
}

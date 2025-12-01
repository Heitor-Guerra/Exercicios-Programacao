#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo *CriaJogo() {
  tJogo *jogo = (tJogo *)malloc(sizeof(tJogo));
  if (jogo == NULL) {
    printf("Falha na Alocacao");
    exit(1);
  }
  jogo->tabuleiro = CriaTabuleiro();
  jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
  jogo->jogador2 = CriaJogador(ID_JOGADOR_2);

  if (jogo->tabuleiro == NULL || jogo->jogador1 == NULL ||
      jogo->jogador2 == NULL) {
    printf("Falha na Alocação");
    exit(1);
  }
  return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo *jogo) {
  int quemJoga = 0, temVencedor = 0;
  while (!AcabouJogo(jogo) && !temVencedor) {
    if (quemJoga % 2 == 0) {
      JogaJogador(jogo->jogador1, jogo->tabuleiro);
    } else {
      JogaJogador(jogo->jogador2, jogo->tabuleiro);
    }
    ImprimeTabuleiro(jogo->tabuleiro);
    if (VenceuJogador(jogo->jogador1, jogo->tabuleiro)) {
      printf("JOGADOR 1 Venceu!\n");
      temVencedor = 1;
    } else if (VenceuJogador(jogo->jogador2, jogo->tabuleiro)) {
      printf("JOGADOR 2 Venceu!\n");
      temVencedor = 1;
    }
    quemJoga++;
  }
  if (!temVencedor) {
    printf("Sem vencedor!\n");
  }
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo *jogo) {
  return !TemPosicaoLivreTabuleiro(jogo->tabuleiro);
}

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
  char escolha = 0;
  printf("Jogar novamente? (s,n)\n");
  scanf("%*[^sn]");
  scanf("%c", &escolha);
  return escolha == 's';
}

/**
 * Libera a memória de uma estrutura do tipo tJogo.
 *
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo *jogo) {
  DestroiJogador(jogo->jogador1);
  DestroiJogador(jogo->jogador2);
  DestroiTabuleiro(jogo->tabuleiro);
  free(jogo);
}

#include "jogo.h"
#include <stdio.h>
/**
 * Cria um jogo e retorna o jogo criado.
 *
 * @return o jogo criado.
 */
tJogo CriaJogo() {
  tJogo jogo;
  jogo.tabuleiro = CriaTabuleiro();
  jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
  jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

  return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo) {
  int quemJoga = 0, semVencedor = 1;
  while (!AcabouJogo(jogo)) {
    if (quemJoga % 2 == 0) {
      jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
    } else {
      jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
    }
    ImprimeTabuleiro(jogo.tabuleiro);
    if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
      puts("JOGADOR 1 Venceu!");
      semVencedor = 0;
      break;
    } else if (VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
      puts("JOGADOR 2 Venceu!");
      semVencedor = 0;
      break;
    }
    quemJoga++;
  }
  if (semVencedor) {
    puts("Sem vencedor!");
  }
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo) { return !TemPosicaoLivreTabuleiro(jogo.tabuleiro); }

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
  puts("Jogar novamente? (s,n)");
  char escolha = 0;
  scanf("%*[^sn]");
  scanf("%c", &escolha);
  return escolha == 's';
}

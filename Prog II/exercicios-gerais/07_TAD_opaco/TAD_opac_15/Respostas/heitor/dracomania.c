#include "dracomania.h"
#include "carta.h"
#include "duelo.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_LISTA 1   /**< Tamanho da lista de cartas. */
#define CADASTRAR 'C' /**< Opção para cadastrar uma nova carta. */
#define LUTAR 'L'     /**< Opção para iniciar uma luta entre duas cartas. */
#define FINALIZAR 'F' /**< Opção para finalizar o programa. */

struct dracomania {
  tCarta *cartas;
  int numCartas;
  int numCartasDesc;

  tDuelo *duelos;
  int numDuelos;
};

/**
 * @brief Cria uma nova instância do jogo Dracomania.
 * @return Retorna um ponteiro para a estrutura criada.
 */
tDracomania CriaDracomania() {
  tDracomania d = (tDracomania)malloc(sizeof(struct dracomania));
  d->cartas = NULL;
  d->numCartas = 0;
  d->numCartasDesc = 0;
  d->duelos = NULL;
  d->numDuelos = 0;

  return d;
}

/**
 * @brief Roda o jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 * @return Retorna um ponteiro para a instância do jogo atualizada.
 */
tDracomania RodaDracomania(tDracomania d) {
  char escolha = 0;
  while (scanf("%c\n", &escolha) == 1 && escolha != FINALIZAR) {
    switch (escolha) {
    case CADASTRAR: {
      tCarta carta = LeCarta();
      if (!EhCartaValida(carta)) {
        d->numCartasDesc++;
        LiberaCarta(carta);
        break;
      }

      int existeId = 0;
      for (int i = 0; i < d->numCartas; i++) {
        if (EhMesmoIdCarta(d->cartas[i], carta)) {
          LiberaCarta(d->cartas[i]);
          d->cartas[i] = carta;
          existeId = 1;
          break;
        }
      }

      if (!existeId) {
        d->cartas =
            (tCarta *)realloc(d->cartas, (d->numCartas + 1) * sizeof(tCarta));
        d->cartas[d->numCartas] = carta;
        d->numCartas++;
      }
      break;
    }
    case LUTAR: {
      d->duelos =
          (tDuelo *)realloc(d->duelos, (d->numDuelos + 1) * sizeof(tDuelo));
      tDuelo duelo = LeDuelo();
      tCarta carta1, carta2;
      for (int i = 0; i < d->numCartas; i++) {
        if (GetIdCarta(d->cartas[i]) == GetC1Duelo(duelo)) {
          carta1 = d->cartas[i];
        }
        if (GetIdCarta(d->cartas[i]) == GetC2Duelo(duelo)) {
          carta2 = d->cartas[i];
        }
      }
      RealizaDuelo(duelo, carta1, carta2);
      d->duelos[d->numDuelos] = duelo;
      d->numDuelos++;
      break;
    }
    }
  }
  return d;
}

/**
 * @brief Imprime o relatório final do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void ImprimeRelatorioDracomania(tDracomania d) {
  printf("Quantidade de Cartas: %d\n", d->numCartas);
  printf("Quantidade de descartadas: %d\n", d->numCartasDesc);
  printf("Quantidade de lutas: %d\n", d->numDuelos);

  if (d->numDuelos > 0) {
    int numDesempates = 0, maiorDiff = 0;
    tCarta maisVitoriosa = d->cartas[0];

    for (int i = 0; i < d->numDuelos; i++) {
      numDesempates += GetDesempateDuelo(d->duelos[i]);
      if (GetDiferencaDuelo(d->duelos[i]) > maiorDiff) {
        maiorDiff = GetDiferencaDuelo(d->duelos[i]);
      }
    }

    for (int i = 0; i < d->numCartas; i++) {
      if (GetNumVitCarta(d->cartas[i]) > GetNumVitCarta(maisVitoriosa)) {
        maisVitoriosa = d->cartas[i];
      }
    }

    printf("Lutas que foram desempatadas: %d\n", numDesempates);
    printf("Carta mais vitoriosa: %s\n", GetNomeCarta(maisVitoriosa));
    printf("Luta com Maior Diferença: %d\n", maiorDiff);
  }
}

/**
 * @brief Libera a memória alocada para a instância do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void LiberaDracomania(tDracomania d) {
  for (int i = 0; i < d->numCartas; i++) {
    LiberaCarta(d->cartas[i]);
  }
  for (int i = 0; i < d->numDuelos; i++) {
    LiberaDuelo(d->duelos[i]);
  }
  if (d->cartas != NULL) {
    free(d->cartas);
  }
  if (d->duelos != NULL) {
    free(d->duelos);
  }
  free(d);
}

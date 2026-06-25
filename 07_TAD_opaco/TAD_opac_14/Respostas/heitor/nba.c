#include "nba.h"
#include "franquia.h"
#include "partida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAD_FRANQUIA 'F' // Caractere para cadastro de franquia
#define CAD_PARTIDA 'P'  // Caractere para cadastro de partida
#define ENCERRAR 'E'     // Caractere para encerrar a NBA

struct nba {
  tFranquia *franquias;
  int qtdF;

  tPartida *partidas;
  int qtdP;
};

/**
 * @brief Cria uma nova instância da NBA.
 *
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA() {
  tNBA nba = (tNBA)malloc(sizeof(struct nba));

  nba->franquias = NULL;
  nba->partidas = NULL;
  nba->qtdF = 0;
  nba->qtdP = 0;

  return nba;
}

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 *
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba) {
  char op = 0;

  while (scanf("%c ", &op) == 1 && op != ENCERRAR) {
    switch (op) {
    case CAD_FRANQUIA:
      nba->franquias = (tFranquia *)realloc(
          nba->franquias, (nba->qtdF + 1) * sizeof(tFranquia));
      nba->franquias[nba->qtdF] = LeFranquia();
      nba->qtdF++;
      break;
    case CAD_PARTIDA:
      nba->partidas = (tPartida *)realloc(nba->partidas,
                                          (nba->qtdP + 1) * sizeof(tPartida));
      nba->partidas[nba->qtdP] = LePartida();
      nba->qtdP++;
      break;
    }
  }

  for (int i = 0; i < nba->qtdP; i++) {
    for (int j = 0; j < nba->qtdF; j++) {
      if (strcmp(GetNomeFranquia(nba->franquias[j]),
                 GetTime1Partida(nba->partidas[i])) == 0) {
        if (GetVencedorPartida(nba->partidas[i]) == TIME_CASA) {
          AdicionaVitoriaCasaFranquia(nba->franquias[j]);
        } else {
          AdicionaDerrotaCasaFranquia(nba->franquias[j]);
        }
      } else if (strcmp(GetNomeFranquia(nba->franquias[j]),
                        GetTime2Partida(nba->partidas[i])) == 0) {
        if (GetVencedorPartida(nba->partidas[i]) == TIME_FORA) {
          AdicionaVitoriaForaFranquia(nba->franquias[j]);
        } else {
          AdicionaDerrotaForaFranquia(nba->franquias[j]);
        }
      }
    }
  }

  return nba;
}

/**
 * @brief Imprime o relatório final da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba) {
  int vOeste = 0, dOeste = 0;
  float aOeste = 0;
  int vLeste = 0, dLeste = 0;
  float aLeste = 0;

  for (int i = 0; i < nba->qtdF; i++) {
    if (strcmp(GetConferenciaFranquia(nba->franquias[i]), "OESTE") == 0) {
      vOeste += GetVitoriaCasaFranquia(nba->franquias[i]) +
                GetVitoriaForaFranquia(nba->franquias[i]);
      dOeste += GetDerrotaCasaFranquia(nba->franquias[i]) +
                GetDerrotaForaFranquia(nba->franquias[i]);
    } else if (strcmp(GetConferenciaFranquia(nba->franquias[i]), "LESTE") ==
               0) {
      vLeste += GetVitoriaCasaFranquia(nba->franquias[i]) +
                GetVitoriaForaFranquia(nba->franquias[i]);
      dLeste += GetDerrotaCasaFranquia(nba->franquias[i]) +
                GetDerrotaForaFranquia(nba->franquias[i]);
    }
  }

  if (vLeste + dLeste != 0) {
    aLeste = (float)vLeste / (vLeste + dLeste);
  }
  if (vOeste + dOeste != 0) {
    aOeste = (float)vOeste / (vOeste + dOeste);
  }

  for (int i = 0; i < nba->qtdF; i++) {
    ImprimeFranquia(nba->franquias[i]);
  }
  printf("LESTE %d %d %.2f\n", vLeste, dLeste, aLeste * 100);
  printf("OESTE %d %d %.2f\n", vOeste, dOeste, aOeste * 100);
}

/**
 * @brief Libera a memória alocada para a instância da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba) {
  for (int i = 0; i < nba->qtdF; i++) {
    LiberaFranquia(nba->franquias[i]);
  }
  for (int i = 0; i < nba->qtdP; i++) {
    LiberaPartida(nba->partidas[i]);
  }
  if (nba->franquias != NULL) {
    free(nba->franquias);
  }
  if (nba->partidas != NULL) {
    free(nba->partidas);
  }

  free(nba);
}

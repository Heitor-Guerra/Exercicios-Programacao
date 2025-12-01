#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_INCREMENTO 1

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que
 * armazenam votos). Ainda nessa função, é lido a quantidade de candidatos e os
 * candidatos são lidos e armazenados A memória necessária para os vetores
 * "presidentes", "governadores" deve ser alocada aqui. Demais ponteiros devem
 * ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao *InicializaEleicao() {
  tEleicao *eleicao = (tEleicao *)malloc(sizeof(tEleicao));
  eleicao->presidentes = NULL;
  eleicao->governadores = NULL;
  eleicao->eleitores = NULL;

  eleicao->totalGovernadores = 0;
  eleicao->totalPresidentes = 0;
  eleicao->totalEleitores = 0;

  eleicao->votosBrancosGovernador = 0;
  eleicao->votosBrancosPresidente = 0;
  eleicao->votosNulosGovernador = 0;
  eleicao->votosNulosPresidente = 0;

  int numCandidatos = 0;
  scanf("%d\n", &numCandidatos);

  for (int i = 0; i < numCandidatos; i++) {
    tCandidato *cand = CriaCandidato();
    LeCandidato(cand);
    char cargo = ObtemCargo(cand);

    switch (cargo) {
    case 'P':
      eleicao->presidentes = (tCandidato **)realloc(
          eleicao->presidentes,
          (eleicao->totalPresidentes + TAM_INCREMENTO) * sizeof(tCandidato *));
      eleicao->presidentes[eleicao->totalPresidentes] = cand;
      eleicao->totalPresidentes++;
      break;
    case 'G':
      eleicao->governadores = (tCandidato **)realloc(
          eleicao->governadores,
          (eleicao->totalGovernadores + TAM_INCREMENTO) * sizeof(tCandidato *));
      eleicao->governadores[eleicao->totalGovernadores] = cand;
      eleicao->totalGovernadores++;
      break;
    }
  }
  return eleicao;
}

void ApagaEleicao(tEleicao *eleicao) {
  for (int i = 0; i < eleicao->totalPresidentes; i++) {
    ApagaCandidato(eleicao->presidentes[i]);
  }
  free(eleicao->presidentes);

  for (int i = 0; i < eleicao->totalGovernadores; i++) {
    ApagaCandidato(eleicao->governadores[i]);
  }
  free(eleicao->governadores);

  for (int i = 0; i < eleicao->totalEleitores; i++) {
    ApagaEleitor(eleicao->eleitores[i]);
  }
  free(eleicao->eleitores);

  free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e
 * armazenados.
 * @param eleicao Eleição a ser realizada.
 */
void RealizaEleicao(tEleicao *eleicao) {
  scanf("%d\n", &eleicao->totalEleitores);
  eleicao->eleitores =
      (tEleitor **)malloc(eleicao->totalEleitores * sizeof(tEleitor *));

  for (int i = 0; i < eleicao->totalEleitores; i++) {
    tEleitor *elei = CriaEleitor();
    LeEleitor(elei);

    eleicao->eleitores[i] = elei;
  }
}

void ApuraVotoPresidenteEleicao(tEleicao *eleicao, int voto) {
  if (voto == 0) {
    eleicao->votosBrancosPresidente++;
    return;
  }

  for (int i = 0; i < eleicao->totalPresidentes; i++) {
    if (VerificaIdCandidato(eleicao->presidentes[i], voto)) {
      IncrementaVotoCandidato(eleicao->presidentes[i]);
      return;
    }
  }

  eleicao->votosNulosPresidente++;
}

void ApuraVotoGovernadorEleicao(tEleicao *eleicao, int voto) {
  if (voto == 0) {
    eleicao->votosBrancosGovernador++;
    return;
  }
  for (int i = 0; i < eleicao->totalGovernadores; i++) {
    if (VerificaIdCandidato(eleicao->governadores[i], voto)) {
      IncrementaVotoCandidato(eleicao->governadores[i]);
      return;
    }
  }
  eleicao->votosNulosGovernador++;
}

void DecideVencedorPresidenteEleicao(tEleicao *eleicao) {
  int maisVotos = -1, empate;
  tCandidato *vencedor = NULL;
  for (int i = 0; i < eleicao->totalPresidentes; i++) {
    int votos = ObtemVotos(eleicao->presidentes[i]);
    if (votos > maisVotos) {
      maisVotos = votos;
      vencedor = eleicao->presidentes[i];
      empate = 0;
    } else if (votos == maisVotos) {
      empate = 1;
    }
  }

  printf("- PRESIDENTE ELEITO: ");
  if (maisVotos <
      eleicao->votosNulosPresidente + eleicao->votosBrancosPresidente) {
    printf("SEM DECISAO\n");
  } else if (empate) {
    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
  } else {
    ImprimeCandidato(vencedor,
                     CalculaPercentualVotos(vencedor, eleicao->totalEleitores));
  }
}

void DecideVencedorGovernadorEleicao(tEleicao *eleicao) {
  int maisVotos = -1, empate;
  tCandidato *vencedor = NULL;
  for (int i = 0; i < eleicao->totalGovernadores; i++) {
    int votos = ObtemVotos(eleicao->governadores[i]);
    if (votos > maisVotos) {
      maisVotos = votos;
      vencedor = eleicao->governadores[i];
      empate = 0;
    } else if (votos == maisVotos) {
      empate = 1;
    }
  }

  printf("- GOVERNADOR ELEITO: ");
  if (maisVotos <
      eleicao->votosNulosGovernador + eleicao->votosBrancosGovernador) {
    printf("SEM DECISAO\n");
  } else if (empate) {
    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
  } else {
    ImprimeCandidato(vencedor,
                     CalculaPercentualVotos(vencedor, eleicao->totalEleitores));
  }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao *eleicao) {
  for (int i = 0; i < eleicao->totalEleitores; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])) {
        printf("ELEICAO ANULADA");
        ApagaEleicao(eleicao);
        exit(1);
      }
    }

    int votoP = ObtemVotoPresidente(eleicao->eleitores[i]);
    ApuraVotoPresidenteEleicao(eleicao, votoP);

    int votoG = ObtemVotoGovernador(eleicao->eleitores[i]);
    ApuraVotoGovernadorEleicao(eleicao, votoG);
  }

  DecideVencedorPresidenteEleicao(eleicao);
  DecideVencedorGovernadorEleicao(eleicao);

  int totalNulos =
      eleicao->votosNulosGovernador + eleicao->votosNulosPresidente;
  int totalBrancos =
      eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente;
  printf("- NULOS E BRANCOS: %d, %d\n", totalNulos, totalBrancos);
}

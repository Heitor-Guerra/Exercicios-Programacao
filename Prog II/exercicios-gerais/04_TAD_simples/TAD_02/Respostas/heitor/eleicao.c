#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>

tEleicao ApuracaoPresidente(tEleicao eleicao, int eleitor) {
  int votoPres, votoNulo;

  // Voto para presidente
  votoPres = ObtemVotoPresidente(eleicao.eleitores[eleitor]);
  votoNulo = 1;
  if (votoPres == 0) {
    votoNulo = 0;
    eleicao.votosBrancosPresidente++;
  }
  for (int j = 0; j < eleicao.totalPresidentes; j++) {
    if (VerificaIdCandidato(eleicao.presidentes[j], votoPres)) {
      eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
      votoNulo = 0;
      break;
    }
  }
  if (votoNulo) {
    eleicao.votosNulosPresidente++;
  }
  return eleicao;
}

tEleicao ApuracaoGovernador(tEleicao eleicao, int eleitor) {
  int votoGov, votoNulo;

  // Voto para governador
  votoGov = ObtemVotoGovernador(eleicao.eleitores[eleitor]);
  votoNulo = 1;
  if (votoGov == 0) {
    votoNulo = 0;
    eleicao.votosBrancosGovernador++;
  }
  for (int j = 0; j < eleicao.totalGovernadores; j++) {
    if (VerificaIdCandidato(eleicao.governadores[j], votoGov)) {
      eleicao.governadores[j] =
          IncrementaVotoCandidato(eleicao.governadores[j]);
      votoNulo = 0;
      break;
    }
  }
  if (votoNulo) {
    eleicao.votosNulosGovernador++;
  }
  return eleicao;
}

void DecisaoPresidente(tEleicao eleicao) {
  // Decisao presidente
  int maisVotosIndex = 0;
  for (int i = 0; i < eleicao.totalPresidentes; i++) {
    if (ObtemVotos(eleicao.presidentes[i]) >
        ObtemVotos(eleicao.presidentes[maisVotosIndex])) {
      maisVotosIndex = i;
    }
  }
  if (ObtemVotos(eleicao.presidentes[maisVotosIndex]) <
      (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)) {
    printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
  } else {
    int empate = 0;
    for (int i = 0; i < eleicao.totalPresidentes; i++) {
      if (ObtemVotos(eleicao.presidentes[maisVotosIndex]) ==
              ObtemVotos(eleicao.presidentes[i]) &&
          !EhMesmoCandidato(eleicao.presidentes[i],
                            eleicao.presidentes[maisVotosIndex])) {
        printf(
            "- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        empate = 1;
        break;
      }
    }
    if (!empate) {
      printf("- PRESIDENTE ELEITO: ");
      ImprimeCandidato(
          eleicao.presidentes[maisVotosIndex],
          CalculaPercentualVotos(eleicao.presidentes[maisVotosIndex],
                                 eleicao.totalEleitores));
    }
  }
}

void DecisaoGovernador(tEleicao eleicao) {
  // Decisao governador
  int maisVotosIndex = 0;
  for (int i = 0; i < eleicao.totalGovernadores; i++) {
    if (ObtemVotos(eleicao.governadores[i]) >
        ObtemVotos(eleicao.governadores[maisVotosIndex])) {
      maisVotosIndex = i;
    }
  }
  if (ObtemVotos(eleicao.governadores[maisVotosIndex]) <
      (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)) {
    printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
  } else {
    int empate = 0;
    for (int i = 0; i < eleicao.totalGovernadores; i++) {
      if (ObtemVotos(eleicao.governadores[maisVotosIndex]) ==
              ObtemVotos(eleicao.governadores[i]) &&
          !EhMesmoCandidato(eleicao.governadores[i],
                            eleicao.governadores[maisVotosIndex])) {
        printf(
            "- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        empate = 1;
        break;
      }
    }
    if (!empate) {
      printf("- GOVERNADOR ELEITO: ");
      ImprimeCandidato(
          eleicao.governadores[maisVotosIndex],
          CalculaPercentualVotos(eleicao.governadores[maisVotosIndex],
                                 eleicao.totalEleitores));
    }
  }
}

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos
 * invalidos). Ainda nessa função, é lido a quantidade de candidatos e os
 * candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao() {
  tEleicao eleicao;
  tCandidato temp;
  int candidatos;
  scanf("%d", &candidatos);

  eleicao.votosBrancosGovernador = 0;
  eleicao.votosNulosGovernador = 0;
  eleicao.votosBrancosPresidente = 0;
  eleicao.votosNulosPresidente = 0;
  eleicao.totalGovernadores = 0;
  eleicao.totalPresidentes = 0;
  for (int i = 0; i < candidatos; i++) {
    temp = LeCandidato();
    switch (ObtemCargo(temp)) {
    case 'P':
      eleicao.presidentes[eleicao.totalPresidentes] = temp;
      eleicao.totalPresidentes++;
      break;
    case 'G':
      eleicao.governadores[eleicao.totalGovernadores] = temp;
      eleicao.totalGovernadores++;
      break;
    }
  }
  return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e
 * armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao) {
  scanf("%d", &eleicao.totalEleitores);

  if (eleicao.totalEleitores > 10) {
    printf("ELEICAO ANULADA\n");
    exit(1);
  }

  for (int i = 0; i < eleicao.totalEleitores; i++) {
    eleicao.eleitores[i] = LeEleitor();
  }
  return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao) {
  int votoPres, votoGov, votoNulo;

  // Apuracao dos votos
  for (int i = 0; i < eleicao.totalEleitores; i++) {
    // Verificar se o candidato nao eh repetido
    for (int j = i - 1; j >= 0; j--) {
      if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])) {
        printf("ELEICAO ANULADA\n");
        exit(1);
      }
    }

    eleicao = ApuracaoPresidente(eleicao, i);
    eleicao = ApuracaoGovernador(eleicao, i);
  }

  DecisaoPresidente(eleicao);
  DecisaoGovernador(eleicao);

  printf("- NULOS E BRANCOS: %d, %d\n",
         eleicao.votosNulosGovernador + eleicao.votosNulosPresidente,
         eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente);
}

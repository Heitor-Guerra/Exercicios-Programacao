#include "candidato.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria um candidato com os dados informados.
 * @param nome Nome do candidato.
 * @param partido Partido do candidato.
 * @param cargo Cargo do candidato.
 * @param id Identificador do candidato.
 * @return Candidato criado.
 */
tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id) {
  tCandidato cand;
  strcpy(cand.nome, nome);
  strcpy(cand.partido, partido);
  cand.cargo = cargo;
  cand.id = id;
  cand.votos = 0;
  return cand;
}

/**
 * @brief Lê um candidato.
 * @return Candidato lido.
 */
tCandidato LeCandidato() { // talvez
  char nome[50], partido[50], cargo;
  int id;
  scanf("\n%[^,], %[^,], %c, %d", nome, partido, &cargo, &id);
  tCandidato candidato = CriaCandidato(nome, partido, cargo, id);
  return candidato;
}

/**
 * @brief Verifica se o identificador do candidato é igual ao informado.
 * @param candidato Candidato a ser verificado.
 * @param id Identificador a ser comparado.
 * @return 1 se o identificador é igual, 0 caso contrário.
 */
int VerificaIdCandidato(tCandidato candidato, int id) {
  return candidato.id == id;
}

/**
 * @brief Verifica se dois candidatos são iguais (dica: utilize para verificar
 * se houve empate).
 * @param candidato1 Primeiro candidato a ser comparado.
 * @param candidato2 Segundo candidato a ser comparado.
 * @return 1 se os candidatos são iguais, 0 caso contrário.
 */
int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2) {
  return candidato1.id == candidato2.id;
}

/**
 * @brief Obtém o cargo do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Cargo do candidato.
 */
char ObtemCargo(tCandidato candidato) { return candidato.cargo; }

/**
 * @brief Incrementa 1 voto ao candidato.
 * @param candidato Candidato a ter os votos incrementados.
 * @return Candidato com a quantidade de votos incrementada.
 */
tCandidato IncrementaVotoCandidato(tCandidato candidato) {
  candidato.votos++;
  return candidato;
}

/**
 * @brief Obtém a quantidade de votos do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Quantidade de votos do candidato.
 */
int ObtemVotos(tCandidato candidato) { return candidato.votos; }

/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de
 * votos (do mesmo cargo).
 * @param candidato Candidato a ser verificado.
 * @param totalVotos Total de votos da eleição.
 * @return Percentual de votos do candidato.
 */
float CalculaPercentualVotos(tCandidato candidato, int totalVotos) {
  return 100.0 * (float)candidato.votos / totalVotos;
}

/**
 * @brief Imprime os dados do candidato na tela.
 * @param candidato Candidato a ser impresso.
 * @param percentualVotos Percentual de votos do candidato.
 */
void ImprimeCandidato(tCandidato candidato, float percentualVotos) {
  printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido,
         candidato.votos, percentualVotos);
}

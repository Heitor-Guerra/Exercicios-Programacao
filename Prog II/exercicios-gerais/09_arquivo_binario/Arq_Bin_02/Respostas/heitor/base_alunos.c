#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos {
  tAluno **alunos;
  int numAlunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 *
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na
 * alocação de memória, o programa é encerrado.
 */
tBaseAlunos *CriarBaseAlunos() {
  tBaseAlunos *base = (tBaseAlunos *)malloc(sizeof(tBaseAlunos));
  base->alunos = NULL;
  base->numAlunos = 0;

  return base;
}

/**
 * @brief Função para destruir uma base de alunos.
 *
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos *baseAlunos) {
  for (int i = 0; i < baseAlunos->numAlunos; i++) {
    DestruirAluno(baseAlunos->alunos[i]);
  }
  free(baseAlunos->alunos);
  free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 *
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos *baseAlunos, char *nomeArquivo) {
  FILE *file;
  file = fopen(nomeArquivo, "rb");

  fread(&baseAlunos->numAlunos, sizeof(int), 1, file);
  baseAlunos->alunos =
      (tAluno **)malloc(baseAlunos->numAlunos * sizeof(tAluno *));

  for (int i = 0; i < baseAlunos->numAlunos; i++) {
    baseAlunos->alunos[i] = LeAluno(file);
  }

  fclose(file);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de
 * alunos.
 *
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento
 * médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos *baseAlunos) {
  float media = 0;
  for (int i = 0; i < baseAlunos->numAlunos; i++) {
    media += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
  }
  return media / baseAlunos->numAlunos;
}

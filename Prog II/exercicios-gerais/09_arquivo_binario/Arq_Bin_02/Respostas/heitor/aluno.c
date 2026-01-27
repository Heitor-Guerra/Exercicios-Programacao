#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME_ALUNO 100
#define TAM_DATA_ALUNO 11
#define TAM_CURSO_ALUNO 50

/**
 * @brief Estrutura para representar um aluno.
 */
struct Aluno {
  char nome[TAM_NOME_ALUNO];
  char data[TAM_DATA_ALUNO];
  char curso[TAM_CURSO_ALUNO];
  int periodo;
  float cra;
};

/**
 * @brief Função para criar um novo aluno.
 *
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de
 * memória, o programa é encerrado.
 */
tAluno *CriarAluno(char *nome, char *dataNascimento, char *curso, int periodo,
                   float coeficienteRendimento) {
  tAluno *a = (tAluno *)malloc(sizeof(tAluno));
  strcpy(a->nome, nome);
  strcpy(a->data, dataNascimento);
  strcpy(a->curso, curso);
  a->periodo = periodo;
  a->cra = coeficienteRendimento;

  return a;
}

/**
 * @brief Função para destruir um aluno.
 *
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno *aluno) { free(aluno); }

/**
 * @brief Função para ler um aluno de um arquivo binário.
 *
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario) {
  char nome[TAM_NOME_ALUNO];
  char data[TAM_DATA_ALUNO];
  char curso[TAM_CURSO_ALUNO];
  int periodo;
  float cra;

  fread(nome, sizeof(char), TAM_NOME_ALUNO, arquivo_binario);
  fread(data, sizeof(char), TAM_DATA_ALUNO, arquivo_binario);
  fread(curso, sizeof(char), TAM_CURSO_ALUNO, arquivo_binario);
  fread(&periodo, sizeof(int), 1, arquivo_binario);
  fread(&cra, sizeof(float), 1, arquivo_binario);

  return CriarAluno(nome, data, curso, periodo, cra);
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 *
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno *aluno) { return aluno->cra; }

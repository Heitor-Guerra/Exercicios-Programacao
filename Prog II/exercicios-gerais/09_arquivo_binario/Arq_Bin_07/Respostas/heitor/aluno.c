#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
  char nome[101];
  char data[101];
  char curso[101];
  float prctConclusao;
  float cra;
};

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe,
 * a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso,
                  float prctConclusao, float cfRendimento) {
  tAluno *aluno = (tAluno *)calloc(1, sizeof(tAluno));

  strcpy(aluno->nome, nome);
  strcpy(aluno->data, dataNascimento);
  strcpy(aluno->curso, curso);
  aluno->prctConclusao = prctConclusao;
  aluno->cra = cfRendimento;

  return aluno;
}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno) { free(aluno); }

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno() {
  char nome[101];
  char data[101];
  char curso[101];
  float prctConclusao;
  float cra;

  scanf("\n%[^\n]\n", nome);
  scanf("%[^\n]\n", data);
  scanf("%[^\n]\n", curso);
  scanf("%f\n", &prctConclusao);
  scanf("%f\n", &cra);

  return CriaAluno(nome, data, curso, prctConclusao, cra);
}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função
 * strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2) {
  return strcmp(aluno1->nome, aluno2->nome);
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file) {
  fwrite(aluno, sizeof(tAluno), 1, file);
  return sizeof(tAluno);
}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file) {
  fread(aluno, sizeof(tAluno), 1, file);
  return sizeof(tAluno);
}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno) { printf("%s\n", aluno->nome); }

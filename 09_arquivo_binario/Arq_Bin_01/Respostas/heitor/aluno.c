#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING_ALUNO 100

struct aluno {
  char nome[TAM_STRING_ALUNO];
  char data[TAM_STRING_ALUNO];
  char curso[TAM_STRING_ALUNO];
  char periodo[TAM_STRING_ALUNO];
  int pConc;
  float cra;
};

Aluno **CriaVetorAlunos(int numeroAlunos) {
  Aluno **alunos = (Aluno **)malloc(numeroAlunos * sizeof(Aluno *));
  return alunos;
}

Aluno *CriaAluno(char *nome, char *dtNasc, char *cursoUfes,
                 char *periodoIngresso, int percConclusao, float CRA) {
  Aluno *a = (Aluno *)malloc(sizeof(Aluno));
  strcpy(a->nome, nome);
  strcpy(a->data, dtNasc);
  strcpy(a->curso, cursoUfes);
  strcpy(a->periodo, periodoIngresso);
  a->pConc = percConclusao;
  a->cra = CRA;

  return a;
}

void LeAlunos(Aluno **vetorAlunos, int numeroAlunos) {
  for (int i = 0; i < numeroAlunos; i++) {
    char nome[TAM_STRING_ALUNO];
    char data[TAM_STRING_ALUNO];
    char curso[TAM_STRING_ALUNO];
    char periodo[TAM_STRING_ALUNO];
    int pConc;
    float cra;
    scanf("\n%[^\n]", nome);
    scanf("\n%[^\n]", data);
    scanf("\n%[^\n]", curso);
    scanf("\n%[^\n]", periodo);
    scanf("\n%d", &pConc);
    scanf("\n%f", &cra);

    vetorAlunos[i] = CriaAluno(nome, data, curso, periodo, pConc, cra);
  }
}

void LiberaAlunos(Aluno **alunos, int numeroAlunos) {
  for (int i = 0; i < numeroAlunos; i++) {
    free(alunos[i]);
  }
  free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
  FILE *file;
  file = fopen(fileName, "wb");

  int total = 0;

  fwrite(&numeroAlunos, sizeof(int), 1, file);
  for (int i = 0; i < numeroAlunos; i++) {
    int size = strlen(alunos[i]->nome);
    fwrite(&size, sizeof(int), 1, file);
    fwrite(alunos[i]->nome, sizeof(char), size, file);
    total += size * sizeof(char) + sizeof(int);

    size = strlen(alunos[i]->data);
    fwrite(&size, sizeof(int), 1, file);
    fwrite(alunos[i]->data, sizeof(char), size, file);
    total += size * sizeof(char) + sizeof(int);

    size = strlen(alunos[i]->curso);
    fwrite(&size, sizeof(int), 1, file);
    fwrite(alunos[i]->curso, sizeof(char), size, file);
    total += size * sizeof(char) + sizeof(int);

    size = strlen(alunos[i]->periodo);
    fwrite(&size, sizeof(int), 1, file);
    fwrite(alunos[i]->periodo, sizeof(char), size, file);
    total += size * sizeof(char) + sizeof(int);

    fwrite(&alunos[i]->pConc, sizeof(int), 1, file);
    total += sizeof(int);

    fwrite(&alunos[i]->cra, sizeof(float), 1, file);
    total += sizeof(float);
  }

  printf("Numero de bytes salvos: %d\n", total);

  fclose(file);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
  FILE *file;
  file = fopen(fileName, "rb");

  int numeroAlunos;

  fread(&numeroAlunos, sizeof(int), 1, file);

  for (int i = 0; i < numeroAlunos; i++) {
    char nome[TAM_STRING_ALUNO];
    char data[TAM_STRING_ALUNO];
    char curso[TAM_STRING_ALUNO];
    char periodo[TAM_STRING_ALUNO];
    int pConc;
    float cra;

    int size;
    fread(&size, sizeof(int), 1, file);
    fread(nome, sizeof(char), size, file);
    nome[size] = '\0';

    fread(&size, sizeof(int), 1, file);
    fread(data, sizeof(char), size, file);
    data[size] = '\0';

    fread(&size, sizeof(int), 1, file);
    fread(curso, sizeof(char), size, file);
    curso[size] = '\0';

    fread(&size, sizeof(int), 1, file);
    fread(periodo, sizeof(char), size, file);
    periodo[size] = '\0';

    fread(&pConc, sizeof(int), 1, file);

    fread(&cra, sizeof(float), 1, file);

    alunos[i] = CriaAluno(nome, data, curso, periodo, pConc, cra);
  }

  fclose(file);
}

void ImprimeAlunos(Aluno **alunos, int numeroAlunos) {
  for (int i = 0; i < numeroAlunos; i++) {
    printf("Aluno %d:\n", i);
    printf("Nome: %s\n", alunos[i]->nome);
    printf("Data Nascimento: %s\n", alunos[i]->data);
    printf("Curso: %s\n", alunos[i]->curso);
    printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
    printf("%% Conclusao do Curso: %d\n", alunos[i]->pConc);
    printf("CRA: %.2f\n", alunos[i]->cra);
  }
}

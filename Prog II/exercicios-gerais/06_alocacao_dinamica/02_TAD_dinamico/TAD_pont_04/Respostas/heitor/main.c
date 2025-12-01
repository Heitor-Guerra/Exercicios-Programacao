#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int numAlunos = 0;
  scanf("%d\n", &numAlunos);
  tAluno **alunos = (tAluno **)malloc(numAlunos * sizeof(tAluno *));

  for (int i = 0; i < numAlunos; i++) {
    alunos[i] = CriaAluno();
    LeAluno(alunos[i]);
  }

  int terminou = 0;
  while (!terminou) {
    for (int i = 1; i < numAlunos; i++) {
      if (ComparaMatricula(alunos[i - 1], alunos[i]) > 0) {
        tAluno *temp = alunos[i - 1];
        alunos[i - 1] = alunos[i];
        alunos[i] = temp;
      }
    }
    terminou = 1;
    for (int i = 1; i < numAlunos; i++) {
      if (ComparaMatricula(alunos[i - 1], alunos[i]) > 0) {
        terminou = 0;
        break;
      }
    }
  }

  for (int i = 0; i < numAlunos; i++) {
    if (VerificaAprovacao(alunos[i])) {
      ImprimeAluno(alunos[i]);
    }
  }

  for (int i = 0; i < numAlunos; i++) {
    ApagaAluno(alunos[i]);
  }
  free(alunos);

  return 0;
}

#include "aluno.h"
#include <stdio.h>

void ordernarAlunos(int numALunos, tAluno *alunos) {
  int pronto = 0;
  tAluno tmp;
  while (!pronto) {
    for (int i = 1; i < numALunos; i++) {
      if (ComparaMatricula(alunos[i - 1], alunos[i]) == 1) {
        tmp = alunos[i];
        alunos[i] = alunos[i - 1];
        alunos[i - 1] = tmp;
      }
    }
    pronto = 1;
    for (int i = 1; i < numALunos; i++) {
      if (ComparaMatricula(alunos[i - 1], alunos[i]) == 1) {
        pronto = 0;
        break;
      }
    }
  }
}

int main() {
  int numALunos;
  scanf("%d\n", &numALunos);
  tAluno alunos[numALunos];

  for (int i = 0; i < numALunos; i++) {
    alunos[i] = LeAluno();
  }
  ordernarAlunos(numALunos, alunos);

  for (int i = 0; i < numALunos; i++) {
    if (VerificaAprovacao(alunos[i])) {
      ImprimeAluno(alunos[i]);
    }
  }

  return 0;
}

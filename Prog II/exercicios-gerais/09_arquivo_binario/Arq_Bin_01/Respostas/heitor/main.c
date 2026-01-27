#include "aluno.h"
#include <stdio.h>

int main() {
  int numAlunos;
  printf("Digite o numero de alunos: ");
  scanf("%d\n", &numAlunos);

  Aluno **alunos = CriaVetorAlunos(numAlunos);
  LeAlunos(alunos, numAlunos);
  SalvaAlunosBinario(alunos, "alunos.bin", numAlunos);
  LiberaAlunos(alunos, numAlunos);

  alunos = CriaVetorAlunos(numAlunos);
  CarregaAlunosBinario(alunos, "alunos.bin");
  ImprimeAlunos(alunos, numAlunos);

  LiberaAlunos(alunos, numAlunos);
  return 0;
}

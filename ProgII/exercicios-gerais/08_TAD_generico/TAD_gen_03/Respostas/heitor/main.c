#include "aluno.h"
#include "relatorio.h"
#include "vector.h"
#include <stdio.h>

int main() {
  int numA;
  Vector *alunos = VectorConstruct();
  scanf("%d\n", &numA);

  for (int i = 0; i < numA; i++) {
    tAluno *aluno = CriaAluno();
    LeAluno(aluno);
    VectorPushBack(alunos, (data_type)aluno);
  }
  ImprimeRelatorio(alunos);

  VectorDestroy(alunos, DestroiAluno);

  return 0;
}

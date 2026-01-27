#include "base_alunos.h"
#include <stdio.h>

int main() {
  tBaseAlunos *base = CriarBaseAlunos();
  char pathArq[100];
  scanf("%s", pathArq);
  LerBaseAlunos(base, pathArq);

  printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n",
         GetCoeficienteRendimentoMedioBaseAlunos(base));

  DestruirBaseAlunos(base);

  return 0;
}

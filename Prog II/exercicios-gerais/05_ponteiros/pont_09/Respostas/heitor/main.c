#include "pessoa.h"
#include <stdio.h>

int main() {
  int numPessoas;
  scanf("%d", &numPessoas);
  tPessoa listaPessoas[numPessoas];

  for (int i = 0; i < numPessoas; i++) {
    listaPessoas[i] = CriaPessoa();
    LePessoa(listaPessoas + i);
  }

  AssociaFamiliasGruposPessoas(listaPessoas);
  for (int i = 0; i < numPessoas; i++) {
    ImprimePessoa(listaPessoas + i);
  }

  return 0;
}

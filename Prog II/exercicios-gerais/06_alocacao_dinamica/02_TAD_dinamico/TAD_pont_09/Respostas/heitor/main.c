#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int numEmpresas;
  scanf("%d\n", &numEmpresas);

  tEmpresa **empresas = (tEmpresa **)malloc(numEmpresas * sizeof(tEmpresa *));

  for (int i = 0; i < numEmpresas; i++) {
    empresas[i] = CriaEmpresa();
    LeEmpresa(empresas[i]);
  }

  for (int i = 0; i < numEmpresas; i++) {
    ImprimeEmpresa(empresas[i]);
  }

  for (int i = 0; i < numEmpresas; i++) {
    ApagaEmpresa(empresas[i]);
  }
  free(empresas);

  return 0;
}

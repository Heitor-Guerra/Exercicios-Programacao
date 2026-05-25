#include "empresa.h"
#include <stdio.h>

int main() {
  int numEmpresas;
  scanf("%d\n", &numEmpresas);
  tEmpresa empresas[numEmpresas];

  for (int i = 0; i < numEmpresas; i++) {
    empresas[i] = leEmpresa();
    scanf("\n");
  }

  for (int i = 0; i < numEmpresas; i++) {
    imprimeEmpresa(empresas[i]);
  }

  return 0;
}

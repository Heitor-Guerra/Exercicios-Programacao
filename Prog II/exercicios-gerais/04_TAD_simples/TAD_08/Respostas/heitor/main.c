#include "departamento.h"
#include <stdio.h>

int main() {
  int numDeps;
  scanf("%d\n", &numDeps);
  tDepartamento deps[numDeps];

  for (int i = 0; i < numDeps; i++) {
    char nome[STRING_MAX];
    char dir[STRING_MAX];
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    int m1, m2, m3;

    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", dir);
    scanf("%[^\n]\n", c1);
    scanf("%[^\n]\n", c2);
    scanf("%[^\n]\n", c3);
    scanf("%d %d %d\n", &m1, &m2, &m3);

    deps[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, dir);
  }
  ordenaPorMediaDepartamentos(deps, numDeps);

  for (int i = 0; i < numDeps; i++) {
    imprimeAtributosDepartamento(deps[i]);
  }

  return 0;
}

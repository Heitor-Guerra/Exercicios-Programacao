#include "departamento.h"
#include <stdio.h>

int main() {
  int numDeptos;
  scanf("%d\n", &numDeptos);
  tDepartamento *deps[numDeptos];

  for (int i = 0; i < numDeptos; i++) {
    char nome[STRING_MAX], diretor[STRING_MAX], c1[STRING_MAX], c2[STRING_MAX],
        c3[STRING_MAX];
    int m1, m2, m3;
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", diretor);
    scanf("%[^\n]\n", c1);
    scanf("%[^\n]\n", c2);
    scanf("%[^\n]\n", c3);

    scanf("%d %d %d\n", &m1, &m2, &m3);

    deps[i] = CriaDepartamento();
    PreencheDadosDepartamento(deps[i], c1, c2, c3, nome, m1, m2, m3, diretor);
  }

  OrdenaPorMediaDepartamentos(deps, numDeptos);

  for (int i = 0; i < numDeptos; i++) {
    ImprimeAtributosDepartamento(deps[i]);
  }

  for (int i = 0; i < numDeptos; i++) {
    LiberaMemoriaDepartamento(deps[i]);
  }

  return 0;
}

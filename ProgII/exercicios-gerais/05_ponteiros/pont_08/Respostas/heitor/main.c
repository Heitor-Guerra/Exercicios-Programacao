#include "tDepartamento.h"
#include <stdio.h>

int main() {
  int numDeptos = 0;
  scanf("%d\n", &numDeptos);
  tDepartamento deps[numDeptos];

  int i = 0;
  while (i < numDeptos) {
    char nome[15], curso1[11], curso2[11], curso3[11], diretor[10];
    int m1, m2, m3;
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", diretor);
    scanf("%[^\n]\n", curso1);
    scanf("%[^\n]\n", curso2);
    scanf("%[^\n]\n", curso3);
    scanf("%d %d %d\n", &m1, &m2, &m3);

    if (m1 < 0 || m1 > 10 || m2 < 0 || m2 > 10 || m3 < 0 || m3 > 10) {
      puts("\nDigite um departamento com médias válidas");
      continue;
    }

    *(deps + i) =
        CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
    i++;
  }

  OrdenaDepartamentosPorMedia(deps, numDeptos);
  for (int i = 0; i < numDeptos; i++) {
    ImprimeAtributosDepartamento(deps[i]);
    printf("\n\n");
  }
}

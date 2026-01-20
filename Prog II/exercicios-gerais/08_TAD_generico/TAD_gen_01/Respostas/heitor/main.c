#include "tadgen.h"
#include <stdio.h>

int main() {
  printf("tad_gen_01\n");
  int num;
  Type tipo;
  printf("Digite o tipo e numero de elementos:\n");
  scanf("%d %d\n", &tipo, &num);

  tGeneric *g = CriaGenerico(tipo, num);
  LeGenerico(g);
  ImprimeGenerico(g);
  DestroiGenerico(g);

  return 0;
}

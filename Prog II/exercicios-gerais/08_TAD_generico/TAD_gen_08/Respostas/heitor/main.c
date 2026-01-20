#include "fila.h"
#include "movel.h"
#include <stdio.h>
#include <string.h>

void DestroiMovelM(DataType data) {
  tMovel *movel = (tMovel *)data;
  DestroiMovel(movel);
}

int main() {
  int ops;
  scanf("%d\n", &ops);
  char op[9];
  Fila *fila = FilaConstruct();

  for (int i = 0; i < ops; i++) {
    scanf("%s", op);
    if (strcmp(op, "ENTRADA") == 0) {
      scanf(" ");
      tMovel *temp = LeMovel();
      FilaPush(fila, temp);
    } else if (strcmp(op, "PRODUZIR") == 0) {
      scanf("\n");
      tMovel *movel = FilaPop(fila);
      ImprimeMovel(movel);
      DestroiMovel(movel);
    }
  }
  FilaDestroy(fila, DestroiMovelM);

  return 0;
}

#include "data.h"
#include <stdio.h>

int main() {
  tData data;
  tData dataIni;
  tData dataFim;
  LeData(&dataIni);
  LeData(&dataFim);
  data = dataIni;
  while (!EhIgual(&data, &dataFim)) {
    ImprimeData(&data);
    printf("\n");
    AvancaParaDiaSeguinte(&data);
  }
  return 0;
}

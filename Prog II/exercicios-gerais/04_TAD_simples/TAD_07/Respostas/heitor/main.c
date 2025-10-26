#include "data.h"
#include <stdio.h>

int main() {
  int dia, mes, ano;
  scanf("%d/%d/%d\n", &dia, &mes, &ano);
  tData data1 = CriaData(dia, mes, ano);

  scanf("%d/%d/%d\n", &dia, &mes, &ano);
  tData data2 = CriaData(dia, mes, ano);

  if (!VerificaDataValida(data1) || !VerificaDataValida(data2)) {
    puts("A primeira e/ou segunda data(s) invalida(s)");
    return 1;
  }

  printf("Primeira data: ");
  ImprimeDataExtenso(data1);
  printf("Segunda data: ");
  ImprimeDataExtenso(data2);

  switch (ComparaData(data1, data2)) {
  case 1:
    puts("A segunda data eh mais antiga");
    break;
  case -1:
    puts("A primeira data eh mais antiga");
    break;
  case 0:
    puts("As datas sao iguais");
    break;
  }

  printf("A diferenca em dias entre as datas eh: %02d dias",
         CalculaDiferencaDias(data1, data2));
  return 0;
}

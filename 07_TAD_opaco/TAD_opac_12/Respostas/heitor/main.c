#include "array.h"
#include <stdio.h>

int main() {
  Array *arr = CriarArray();
  LerArray(arr);

  int numEscolhido;
  scanf("%d\n", &numEscolhido);

  OrdenarArray(arr);
  int index = BuscaBinariaArray(arr, numEscolhido);

  if (index == -1) {
    printf("Elemento %d não encontrado no array (%d).\n", numEscolhido, index);
  } else {
    printf("Elemento %d encontrado no índice %d.\n", numEscolhido, index);
  }

  DestruirArray(arr);
  return 0;
}

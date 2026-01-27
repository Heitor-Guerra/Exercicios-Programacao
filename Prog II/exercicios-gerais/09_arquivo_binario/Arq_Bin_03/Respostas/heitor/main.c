#include "imagem.h"
#include <stdio.h>

int main() {
  char pathToFile[100];
  scanf("%s", pathToFile);
  Imagem *img = LerImagem(pathToFile);
  printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(img));
  ImprimirImagem(img);
  DestruirImagem(img);

  return 0;
}

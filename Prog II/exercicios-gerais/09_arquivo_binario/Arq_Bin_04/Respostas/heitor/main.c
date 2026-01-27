#include "histograma.h"
#include "imagem.h"
#include <stdio.h>

int main() {
  char pathToFile[100];
  int numI;
  scanf("%s\n", pathToFile);
  Imagem *img = LerImagem(pathToFile);

  scanf("%d\n", &numI);
  Histograma *hist = CalcularHistograma(img, numI);
  MostrarHistograma(hist);

  DestruirHistograma(hist);
  DestruirImagem(img);
  return 0;
}

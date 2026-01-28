#include "estabelecimento.h"

int main() {
  tEstabelecimento *est = CriaEstabelecimento();
  LeEstabelecimento(est);
  ImprimeProdutosEmFaltaEstabelecimento(est);
  DestroiEstabelecimento(est);
  return 0;
}

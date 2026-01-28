#include "estabelecimento.h"

int main() {
  tEstabelecimento *est = CriaEstabelecimento();
  LeEstabelecimento(est);
  ImprimeRelatorioEstabelecimento(est);
  DestroiEstabelecimento(est);
  return 0;
}

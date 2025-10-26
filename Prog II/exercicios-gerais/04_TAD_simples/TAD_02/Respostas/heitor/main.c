#include "eleicao.h"

int main() {
  tEleicao eleicao = InicializaEleicao();

  eleicao = RealizaEleicao(eleicao);

  ImprimeResultadoEleicao(eleicao);
  return 0;
}

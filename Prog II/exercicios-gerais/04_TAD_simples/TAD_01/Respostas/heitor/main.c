#include "jogo.h"

int main() {
  tJogo jogo;

  do {

    jogo = CriaJogo();
    ComecaJogo(jogo);

  } while (ContinuaJogo());

  return 0;
}

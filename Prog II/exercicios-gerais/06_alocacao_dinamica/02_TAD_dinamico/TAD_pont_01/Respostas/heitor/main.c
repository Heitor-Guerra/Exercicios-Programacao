#include "jogo.h"

int main() {
  do {
    tJogo *jogo = CriaJogo();

    ComecaJogo(jogo);

    DestroiJogo(jogo);
  } while (ContinuaJogo());
  return 0;
}

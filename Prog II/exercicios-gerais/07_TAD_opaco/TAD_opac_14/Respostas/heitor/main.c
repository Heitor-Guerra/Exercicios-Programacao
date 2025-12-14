#include "nba.h"

int main() {
  tNBA nba = CriaNBA();

  nba = RodaNBA(nba);

  ImprimeRelatorioNBA(nba);

  LiberaNBA(nba);
  return 0;
}

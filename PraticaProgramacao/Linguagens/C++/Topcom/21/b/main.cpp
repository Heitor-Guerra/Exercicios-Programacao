#include <iostream>

int search(int y, int x, int tam, char **mapa) {
  int num = 0;
  int xAnt = x, yAnt = y;

  while (true) {
    int xNext = -1, yNext = -1;
    for (int i = y - 1; i <= y + 1; i++) {
      for (int j = x - 1; j <= x + 1; j++) {
        if (i < 0 || i >= tam || j < 0 || j >= tam) {
          continue;
        }
        if ((i == y && j == x) || (i == yAnt && j == xAnt)) {
          continue;
        }
        if (mapa[i][j] == 'T') {
          return num;
        } else if (mapa[i][j] == 'X') {
          yNext = i;
          xNext = j;
        }
      }
    }

    if (yNext == -1 || xNext == -1) {
      return -1;
    }

    yAnt = y;
    xAnt = x;
    y = yNext;
    x = xNext;
    num++;
  }
  return num;
}

int main() {
  int jogadores[4];
  for (int i = 0; i < 4; i++) {
    jogadores[i] = -1;
  }
  int tam;

  std::cin >> tam;
  char **mapa;
  mapa = new char *[tam];
  for (int i = 0; i < tam; i++) {
    mapa[i] = new char[tam];
    for (int j = 0; j < tam; j++) {
      std::cin >> mapa[i][j];
    }
  }

  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      char val = mapa[i][j];
      if (val >= '1' && val <= '4') {
        jogadores[val - '1'] = search(i, j, tam, mapa);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    if (jogadores[i] != -1) {
      std::cout << "Jogador " << i + 1 << ": " << jogadores[i] << '\n';
    }
  }

  return 0;
}

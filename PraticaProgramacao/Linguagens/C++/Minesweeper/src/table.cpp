#include "table.h"
#include <bits/stdc++.h>
#include <iostream>

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int Table::table[2][SIZE_TABLE][SIZE_TABLE];

Table::Table(int numBombs) {
  srand(time(0));
  totalBombs = numBombs;

  int i = 0;
  while (i < numBombs) {
    int x = std::rand() % SIZE_TABLE;
    int y = std::rand() % SIZE_TABLE;
    if (table[0][y][x] == -1) {
      continue;
    }
    table[0][y][x] = -1;
    i++;
  }

  for (int i = 0; i < SIZE_TABLE; i++) {
    for (int j = 0; j < SIZE_TABLE; j++) {
      if (table[0][i][j] != -1) {
        table[0][i][j] = numBombsAround(i, j);
      }
      table[1][i][j] = 0;
    }
  }
}

int Table::numBombsAround(int x, int y) {
  int num = 0;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < SIZE_TABLE && ny >= 0 && ny < SIZE_TABLE) {
      num += (table[0][nx][ny] == -1);
    }
  }

  return num;
}

void Table::print() {
  std::cout << "Number of Bombs: " << totalBombs << '\n';
  for (int i = 0; i < SIZE_TABLE; i++) {
    for (int j = 0; j < SIZE_TABLE; j++) {
      if (table[1][i][j] == 0) {
        std::cout << "# ";
      } else {
        std::cout << table[0][i][j] << ' ';
      }
    }
    std::cout << '\n';
  }
}

void Table::printFull() {
  std::cout << "Number of Bombs: " << totalBombs << '\n';
  for (int i = 0; i < SIZE_TABLE; i++) {
    for (int j = 0; j < SIZE_TABLE; j++) {
      if (table[0][i][j] == -1) {
        std::cout << "B ";
      } else {
        std::cout << table[0][i][j] << ' ';
      }
    }
    std::cout << '\n';
  }
}

bool Table::markPosition() {
  int x = -1, y = -1;
  do {
    std::cout << "Choose a position to mark (x,y): ";
    std::cin >> x >> y;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  } while (x < 0 || y < 0 || x >= SIZE_TABLE || y >= SIZE_TABLE ||
           table[1][y][x] == 1);

  table[1][y][x] = 1;
  if (table[0][y][x] == -1) {
    return false;
  }
  return true;
}

bool Table::full() {
  for (int i = 0; i < SIZE_TABLE; i++) {
    for (int j = 0; j < SIZE_TABLE; j++) {
      if (table[1][i][j] == 0 && table[0][i][j] != -1) {
        return false;
      }
    }
  }
  return true;
}

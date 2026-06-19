#include <iostream>
#include <tuple>
#include <vector>

void print(std::vector<std::vector<char>> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)v[0].size(); j++) {
      std::cout << v[i][j];
    }
    std::cout << std::endl;
  }
}

int flood(std::vector<std::vector<char>> v) {
  int changes = 1;
  while (changes != 0) {
    changes = 0;

    for (int i = 0; i < (int)v.size(); i++) {
      for (int j = 0; j < (int)v[0].size(); j++) {
        if (v[i][j] == '*') {
          for (int k = -1; k <= 1; k += 2) {
            if (i + k >= 0 && i + k < (int)v.size()) {
              if (v[i + k][j] == '#') {
                changes++;
                v[i + k][j] = '*';
              }
            }
            if (j + k >= 0 && j + k < (int)v[0].size()) {
              if (v[i][j + k] == '#') {
                changes++;
                v[i][j + k] = '*';
              }
            }
          }
        }
      }
    }
  }

  int numTrees = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)v[0].size(); j++) {
      if (v[i][j] == '#') {
        numTrees++;
      }
    }
  }

  return numTrees;
}

int main() {
  int lines, cols;
  std::cin >> lines;
  std::cin >> cols;

  std::vector<std::vector<char>> map(lines, std::vector<char>(cols));
  std::vector<std::tuple<int, int>> trees;

  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < cols; j++) {
      char dummy;
      std::cin >> map[i][j];
      if (map[i][j] == '#') {
        trees.push_back(std::make_tuple(i, j));
      }
      if (j != cols - 1) {
        std::cin >> dummy;
      }
    }
  }

  std::tuple<int, int> best_tree;
  int max_trees = 0;
  for (int i = 0; i < (int)trees.size(); i++) {
    if (i == 0) {
      best_tree = trees[0];
    }
    std::vector<std::vector<char>> map_copy = map;
    int y = std::get<0>(trees[i]);
    int x = std::get<1>(trees[i]);
    map_copy[y][x] = 'o';

    int survivor_trees = flood(map_copy);

    if (survivor_trees > max_trees) {
      max_trees = survivor_trees;
      best_tree = trees[i];
    }
  }

  int original_trees = flood(map);

  if (max_trees > original_trees) {
    std::cout << "POSICAO DA ARVORE CORTADA: (" << std::get<0>(best_tree) + 1
              << ',' << std::get<1>(best_tree) + 1 << ')' << std::endl;
    std::cout << "TOTAL DE ARVORES SOBREVIVENTES: " << max_trees;
  } else {
    std::cout << "POSICAO DA ARVORE CORTADA: -" << std::endl;
    std::cout << "TOTAL DE ARVORES SOBREVIVENTES: 0";
  }

  return 0;
}

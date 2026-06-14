#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::vector<int> s;
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int val;
    std::cin >> val;
    s.push_back(val);
  }

  std::vector<bool> wins(n + 1, false);
  for (int i : s) {
    wins[i] = true;
  }

  for (int i = 1; i <= n; i++) {
    if (wins[i] == true) {
      continue;
    }
    for (int j : s) {
      if (j <= i && wins[i - j] == false) {
        wins[i] = true;
        break;
      }
    }
  }

  std::cout << wins[n] << std::endl;

  return 0;
}

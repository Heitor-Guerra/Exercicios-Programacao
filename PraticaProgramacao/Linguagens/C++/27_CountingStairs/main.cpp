#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n <= 2) {
    cout << n;
    return 0;
  } else if (n == 3) {
    cout << 4;
    return 0;
  }

  vector<int> ways(n + 1, 0);

  ways[0] = 1;
  ways[1] = 1;
  ways[2] = 2;
  ways[3] = 4;

  for (int i = 4; i <= n; i++) {
    if (ways[i - 1] != 0) {
      ways[i] += ways[i - 1];
    }
    if (ways[i - 2] != 0) {
      ways[i] += ways[i - 2];
    }
    if (ways[i - 3] != 0) {
      ways[i] += ways[i - 3];
    }
  }
  cout << ways[n];

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> ways(n + 1, 0);
  if (n <= 2) {
    cout << n;
    return 0;
  }
  ways[0] = 0;
  ways[1] = 1;
  ways[2] = 2;

  for (int i = 3; i <= n; i++) {
    if (ways[i - 1] != 0) {
      ways[i] += ways[i - 1];
    }
    if (ways[i - 2] != 0) {
      ways[i] += ways[i - 2];
    }
  }

  cout << ways[n];

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n <= 2) {
    cout << max(0, n - 1);
    return 0;
  }

  vector<int> f(n + 1);
  f[0] = 0;
  f[1] = 0;
  f[2] = 1;

  for (int i = 3; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2] + f[i - 3];
  }

  cout << f[n];

  return 0;
}

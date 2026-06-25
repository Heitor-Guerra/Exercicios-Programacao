#include <iostream>
#include <vector>
using namespace std;

void add_multiples(vector<bool> &v, int tam, int val) {
  for (int i = val; i <= tam; i += val) {
    v[i] = false;
  }
}

int main() {
  int n;
  cin >> n;
  vector<bool> values(n + 1, true);
  int sum = 0;

  for (int i = 2; i <= n; i++) {
    if (values[i] == true) {
      add_multiples(values, n, i);
      sum += i;
    }
  }

  cout << sum;

  return 0;
}

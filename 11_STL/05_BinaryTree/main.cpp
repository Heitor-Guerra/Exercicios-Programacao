#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  map<string, int> m;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string k;
    cin >> k;
    m[k]++;
  }

  for (pair<string, int> p : m) {
    cout << p.first << ' ' << p.second << endl;
  }

  return 0;
}

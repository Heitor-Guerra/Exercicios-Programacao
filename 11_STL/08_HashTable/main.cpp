#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int n, dummy;
  cin >> n;
  cin >> dummy;
  unordered_map<string, string> m;
  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;

    if (cmd == "SET") {
      string name, msg;
      cin >> name;
      getline(cin, msg);
      m[name] = msg;
    } else if (cmd == "GET") {
      string name;
      cin >> name;
      cout << m[name] << endl;
    }
  }
  return 0;
}

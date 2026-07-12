#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int n;
  stack<string> q;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string cmd;

    cin >> cmd;

    if (cmd == "PUSH") {
      string s;
      cin >> s;
      q.push(s);
    } else if (cmd == "POP") {
      cout << '\n' << q.top();
      q.pop();
    }
  }

  return 0;
}

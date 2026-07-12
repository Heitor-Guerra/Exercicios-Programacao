#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
  int n;
  queue<string> q;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string cmd;

    cin >> cmd;

    if (cmd == "ENQUEUE") {
      string s;
      cin >> s;
      q.push(s);
    } else if (cmd == "DEQUEUE") {
      cout << '\n' << q.front();
      q.pop();
    }
  }

  return 0;
}

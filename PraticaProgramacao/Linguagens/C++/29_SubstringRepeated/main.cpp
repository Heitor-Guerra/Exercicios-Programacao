#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<bool> chars(256, false);

  int maxLen = 0;
  int len = 0;
  int start = 0;
  for (int i = 0; i < s.length(); i++) {
    while (chars[s[i]]) {
      chars[s[start]] = false;
      start++;
    }

    len = i - start + 1;
    chars[s[i]] = true;
    if (len > maxLen) {
      maxLen = len;
    }
  }

  cout << maxLen;

  return 0;
}

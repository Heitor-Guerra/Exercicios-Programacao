#include <iostream>
#include <string>
using namespace std;

bool isPalindromic(string s) {
  auto it1 = s.begin();
  auto it2 = s.end() - 1;

  while (it1 < it2) {
    if (*it1 != *it2) {
      return false;
    }
    it1++;
    it2--;
  }
  return true;
}

int main() {
  string s;
  cin >> s;

  auto it1 = s.begin();

  int maxLen = 1;
  while (it1 != s.end()) {
    auto it2 = s.end();

    while (it1 < it2) {
      string a = string(it1, it2);
      if (isPalindromic(a)) {
        if (maxLen < a.length()) {
          maxLen = a.length();
        }
      }

      it2--;
    }

    it1++;
  }

  cout << maxLen;

  return 0;
}

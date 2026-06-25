#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int numRows;
  cin >> numRows;

  string result;
  auto it = s.begin();
  vector<vector<char>> matrix(numRows, vector<char>(s.length() / 2));
  bool finished = false;
  while (!finished) {
    for (int i = 0; i < numRows; i++) {
    }
    it++;
  }

  return 0;
}

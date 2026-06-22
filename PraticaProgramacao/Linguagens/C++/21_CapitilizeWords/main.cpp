#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string sentence;
  getline(cin, sentence);
  istringstream iss(sentence);

  vector<string> words;
  sentence.push_back(' ');

  int beginWord = 0;
  int n = sentence.length();
  for (int i = 0; i < n; i++) {
    if (sentence[i] == ' ') {
      words.push_back(sentence.substr(beginWord, i - beginWord));
      beginWord = i + 1;
    }
  }

  for (string it : words) {
    for (int i = 0; i < it.length(); i++) {
      if (it[i] >= 'a' && it[i] <= 'z') {
        it[i] += 'A' - 'a';
        break;
      } else if (it[i] >= 'A' && it[i] <= 'Z') {
        break;
      }
    }
    cout << it << ' ';
  }

  return 0;
}

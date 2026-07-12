#include <forward_list>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;

  forward_list<string> playlist;

  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;

    if (cmd == "ADD_BEGIN") {
      string music;
      cin >> music;
      playlist.push_front(music);
    } else if (cmd == "ADD_AFTER") {
      string music, reference;
      cin >> reference >> music;
      auto it = playlist.begin();
      while (*it != reference && it != playlist.end()) {
        it++;
      }
      playlist.insert_after(it, music);
    } else if (cmd == "REMOVE") {
      string music;
      cin >> music;
      playlist.remove(music);
    }
  }

  for (string m : playlist) {
    cout << m << endl;
  }

  return 0;
}

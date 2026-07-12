#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Process {

public:
  string name;
  string category;
  int id;
  int prio;
  Process(string name, string category, int id, int prio) {
    this->name = name;
    this->category = category;
    this->id = id;
    this->prio = prio;
  }

  bool less(const Process &b) const { return this->prio < b.prio; }
};

class Cmp {
public:
  bool operator()(const Process &a, const Process &b) const {
    return a.less(b);
  }
};

int main() {
  int n;
  priority_queue<Process, vector<Process>, Cmp> q;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string name, category;
    int id, prio;

    cin >> name >> category >> id >> prio;

    Process p(name, category, id, prio);
    q.push(p);
  }

  while (!q.empty()) {
    Process p = q.top();
    cout << p.name << ' ' << p.category << ' ' << p.id << ' ' << p.prio << endl;
    q.pop();
  }

  return 0;
}

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Program {
public:
  string name;
  string type;
  int priority;
  int load;
  int start_iteration;
  int last_use;
};

struct CompareSO {
  bool operator()(const Program &a, const Program &b) const {
    if (a.priority != b.priority)
      return a.priority < b.priority;
    if (a.load != b.load)
      return a.load > b.load;
    return a.name > b.name;
  }
};

struct CompareUSER {
  bool operator()(const Program &a, const Program &b) const {
    if (a.priority != b.priority)
      return a.priority < b.priority;
    if (a.last_use != b.last_use)
      return a.last_use > b.last_use;
    return a.name > b.name;
  }
};

int main() {
  int n;
  cin >> n;

  vector<Program> all_programs(n);
  for (int i = 0; i < n; ++i) {
    cin >> all_programs[i].name >> all_programs[i].type >>
        all_programs[i].priority >> all_programs[i].load >>
        all_programs[i].start_iteration;
    all_programs[i].last_use = -1;
  }

  queue<Program> rt_queue;
  priority_queue<Program, vector<Program>, CompareSO> so_queue;
  priority_queue<Program, vector<Program>, CompareUSER> user_queue;

  int iteration = 0;
  int remaining = n;
  bool so_turn = true;

  while (remaining > 0) {

    for (Program &prog : all_programs) {
      if (prog.start_iteration == iteration) {
        if (prog.type == "RT")
          rt_queue.push(prog);
        else if (prog.type == "SO")
          so_queue.push(prog);
        else if (prog.type == "USER")
          user_queue.push(prog);
      }
    }

    if (!rt_queue.empty()) {
      Program p = rt_queue.front();
      rt_queue.pop();

      p.load--;
      if (p.load == 0) {
        cout << p.name << " " << iteration << endl;
        remaining--;
      } else {
        p.last_use = iteration;
        rt_queue.push(p);
      }
    } else {
      if (so_turn) {
        if (!so_queue.empty()) {
          Program p = so_queue.top();
          so_queue.pop();

          p.load--;
          if (p.load == 0) {
            cout << p.name << " " << iteration << endl;
            remaining--;
          } else {
            p.last_use = iteration;
            so_queue.push(p);
          }
          so_turn = false;
        } else if (!user_queue.empty()) {
          so_turn = false;
          continue;
        }
      } else {
        if (!user_queue.empty()) {
          Program p = user_queue.top();
          user_queue.pop();

          p.load--;
          if (p.load == 0) {
            cout << p.name << " " << iteration << endl;
            remaining--;
          } else {
            p.last_use = iteration;
            user_queue.push(p);
          }
          so_turn = true;
        } else if (!so_queue.empty()) {
          so_turn = true;
          continue;
        }
      }
    }

    iteration++;
  }

  return 0;
}

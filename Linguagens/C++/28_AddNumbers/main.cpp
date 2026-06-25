#include <forward_list>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  forward_list<int> l1;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    l1.push_front(val);
  }

  cin >> m;
  forward_list<int> l2;

  for (int i = 0; i < m; i++) {
    int val;
    cin >> val;
    l2.push_front(val);
  }

  int carry = 0;
  vector<int> res;
  while (!l1.empty() && !l2.empty()) {
    int n1 = l1.front();
    l1.pop_front();
    int n2 = l2.front();
    l2.pop_front();

    int sum = n1 + n2 + carry;
    res.push_back(sum % 10);
    carry = sum / 10;
  }
  forward_list<int> answer;
  while (res.size() != 0) {
    answer.push_front(res.back());
    res.pop_back();
  }

  answer.reverse();
  while (!answer.empty()) {
    cout << answer.front();
    answer.pop_front();
  }

  return 0;
}

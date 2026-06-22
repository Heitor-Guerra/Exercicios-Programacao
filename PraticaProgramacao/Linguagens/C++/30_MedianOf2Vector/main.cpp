#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> num1(n);
  for (int i = 0; i < n; i++) {
    cin >> num1[i];
  }
  cin >> m;
  sort(num1.begin(), num1.end());
  vector<int> num2(m);
  for (int i = 0; i < m; i++) {
    cin >> num2[i];
  }
  sort(num2.begin(), num2.end());

  auto it1 = num1.begin();
  auto it2 = num2.begin();

  vector<int> all(n + m);
  for (int i = 0; i < n + m; i++) {
    if (it1 == num1.end()) {
      all[i] = *it2;
      it2++;
    } else if (it2 == num2.end()) {
      all[i] = *it1;
      it1++;
    } else {
      int n1 = *it1;
      int n2 = *it2;
      if (n1 >= n2) {
        all[i] = n2;
        it2++;
      } else {
        all[i] = n1;
        it1++;
      }
    }
  }

  int mid = all.size();
  if (mid % 2 == 0) {
    cout << (all[mid / 2] + all[mid / 2 - 1]) / 2.0;
  } else {
    cout << all[mid / 2];
  }

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int tam;
  cin >> tam;
  vector<int> nums(tam);

  for (int i = 0; i < tam; i++) {
    cin >> nums[i];
  }
  int target;
  cin >> target;

  // for (int i = 0; i < nums.size(); i++) {
  //   int sum = target;
  //   for (int j = i; j < nums.size(); j++) {
  //     sum -= nums[j];
  //     if (sum == 0) {
  //       cout << '[' << i << ", " << j << ']' << endl;
  //     } else if (sum < 0) {
  //       break;
  //     }
  //   }
  // }

  int start = 0;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (sum == target) {
      cout << '[' << start << ", " << i - 1 << ']' << endl;
    }
    sum += nums[i];

    while (sum > target) {
      sum -= nums[start];
      start++;
    }
  }

  if (sum == target) {
    cout << '[' << start << ", " << nums.size() - 1 << ']' << endl;
  }

  return 0;
}

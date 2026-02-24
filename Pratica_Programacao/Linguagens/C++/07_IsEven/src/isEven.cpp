#include <iostream>

inline bool isEven(int num) { return num % 2 == 0; }

int main() {
  int num;
  std::cin >> num;
  if (isEven(num)) {
    std::cout << num << " is an even number\n";
  } else {
    std::cout << num << " is not an even number\n";
  }

  return 0;
}

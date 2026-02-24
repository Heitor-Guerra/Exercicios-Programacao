#include <iostream>

int main() {
  int num1, num2;
  std::cin >> num1;
  std::cin >> num2;
  std::cout << "a = " << num1 << ", b = " << num2;

  int temp = num1;
  num1 = num2;
  num2 = temp;

  std::cout << "\na = " << num1 << ", b = " << num2;
  return 0;
}

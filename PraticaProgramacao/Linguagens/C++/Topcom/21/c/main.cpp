#include <iostream>

int main() {
  int num;
  long long int result = 1;
  std::cin >> num;

  if (num < 1 || num > 20) {
    std::cout << "INVALIDO";
    return 1;
  }

  for (int i = num; i > 1; i--) {
    result *= i;
  }

  std::cout << result;

  return 0;
}

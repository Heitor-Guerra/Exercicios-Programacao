#include <iostream>

int main() {
  std::string number;
  std::cout << "Write a number: \n";
  std::cin >> number;

  bool isP = true;
  auto i = number.begin(), j = number.end() - 1;
  while (i <= j) {
    std::cout << *i << "eh i e " << *j << "eh j\n";
    if (*i != *j) {
      isP = false;
      break;
    }
    i++;
    j--;
  }

  if (isP) {
    std::cout << number << " is a Palindrome\n";
  } else {
    std::cout << number << " is not a Palindrome\n";
  }

  return 0;
}

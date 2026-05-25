#include <iostream>

int main() {
  char character;
  std::cout << "Character = ";
  std::cin >> character;
  std::cout << "ASCII Value of '" << character << "' = " << (int)character
            << '\n';

  return 0;
}

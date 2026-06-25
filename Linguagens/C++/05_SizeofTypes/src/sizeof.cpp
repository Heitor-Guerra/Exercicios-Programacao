#include <iostream>

int main() {
  std::cout << "Size of int " << sizeof(int) << " bytes\n";
  std::cout << "Size of float " << sizeof(float) << " bytes\n";
  std::cout << "Size of double " << sizeof(double) << " bytes\n";
  std::cout << "Size of char " << sizeof(char) << " bytes\n";
  std::cout << "Size of int* " << sizeof(int *) << " bytes\n";
  return 0;
}

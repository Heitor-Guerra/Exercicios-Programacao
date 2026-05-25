#include <iomanip>
#include <iostream>

int main() {
  float money;
  float rate;
  int time;

  std::cin >> money;
  std::cin >> rate;
  rate /= 100;
  std::cin >> time;

  double interest = 0;
  for (int i = 0; i < time; i++) {
    interest += money * rate;
    money *= 1 + rate;
  }

  std::cout << "Compound Interest = " << std::setprecision(7) << interest;
}

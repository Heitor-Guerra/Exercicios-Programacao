#include "table.h"
#include <cstdlib>
#include <iostream>

int main() {
  Table table(15);

  while (!table.full()) {
    system("clear");
    table.print();
    if (!table.markPosition()) {
      system("clear");
      table.printFull();
      std::cout << "You Lose";
      return 0;
    }
  }

  std::cout << "Congrats, you won";

  return 0;
}

#include <iostream>

int main() {
  int nums[3];
  int maior = 0;
  int maiorI = 0;
  for (int i = 0; i < 3; i++) {
    std::cin >> nums[i];
    if (nums[i] > maior) {
      maior = nums[i];
      maiorI = i;
    }
  }
  std::cout << "Maior Indice: " << maiorI << " | Valor: " << maior << std::endl;

  return 0;
}

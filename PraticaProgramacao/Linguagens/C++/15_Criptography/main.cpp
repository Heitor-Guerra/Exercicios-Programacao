#include <iostream>
#include <vector>

bool isPresent(std::vector<char> v, char c) {
  for (auto i : v) {
    if (i == c) {
      return true;
    }
  }
  return false;
}

int main() {
  char digitos[256];
  for (int i = 0; i < 256; i++) {
    digitos[i] = (char)i;
  }
  std::vector<char> values;

  int numT;
  std::cin >> numT;

  for (int i = 0; i < numT; i++) {
    char key, value;
    std::cin >> key;
    std::cin.ignore(2);
    std::cin >> value;
    if ((digitos[(int)key] != key && digitos[(int)key] != value) ||
        isPresent(values, value)) {
      std::cout << "Erro" << std::endl;
      exit(1);
    }
    digitos[(int)key] = value;
    values.push_back(value);
  }

  int numL;
  std::cin >> numL;
  std::cin.ignore();
  for (int i = 0; i < numL; i++) {
    std::string sentence;
    std::getline(std::cin, sentence);
    for (auto i = sentence.begin(); i != sentence.end(); i++) {
      *i = digitos[(int)*i];
    }

    std::cout << sentence << std::endl;
  }

  return 0;
}

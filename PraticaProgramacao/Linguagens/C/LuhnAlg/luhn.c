#include <stdbool.h>
#include <string.h>

#define ERROR_VALUE -1;

int sumDigits(const char *num) {
  int sum = 0, secondCharacter = 0, aux, numbers = strlen(num);
  for (int i = strlen(num) - 1; i >= 0; i--) {
    if (num[i] < '0' || num[i] > '9') {
      if (num[i] != ' ') {
        return ERROR_VALUE;
      }
      numbers--;
      continue;
    }
    if (!secondCharacter) {
      sum += num[i] - '0';
      secondCharacter = 1;
    } else {
      aux = (num[i] - '0') * 2;
      if (aux > 9) {
        aux -= 9;
      }
      sum += aux;
      secondCharacter = 0;
    }
  }
  if (numbers <= 1) {
    return ERROR_VALUE;
  }
  return sum;
}

bool luhn(const char *num) {
  int sum;

  sum = sumDigits(num);

  if (sum % 10 == 0) {
    return true;
  }
  return false;
}

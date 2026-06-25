#include <math.h>
#include <stdio.h>

int main() {
  int numDec, numOct = 0, i, casaDecimal = 0;

  scanf("%d", &numDec);

  while (numDec > 0) {
    numOct += (numDec % 8) * pow(10, casaDecimal);
    numDec /= 8;
    casaDecimal++;
  }
  printf("%d", numOct);

  return 0;
}

#include <stdio.h>

int universalHash(int seed, int updateValue, int hashSize, char *str) {
  int hashVal = 0;
  for (; *str != '\0'; str++) {
    hashVal = (seed * hashVal + *str) % hashSize;
    seed = (seed * updateValue) % (hashSize - 1);
  }

  return hashVal;
}

int main() {
  int seed;
  int updateValue;
  int hashSize;
  int nStrings;

  scanf("%d %d %d", &seed, &updateValue, &hashSize);
  scanf("\n%d", &nStrings);

  for (int i = 0; i < nStrings; i++) {
    char string[32];
    scanf("\n%s", string);
    printf("%d\n", universalHash(seed, updateValue, hashSize, string));
  }

  return 0;
}

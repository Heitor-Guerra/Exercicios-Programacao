#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_pangram(const char *sentence) {
  int *charactersChecked = (int *)malloc(sizeof(int) * 26);
  for (int i = 0; i < 26; i++) {
    charactersChecked[i] = 0;
  }
  for (size_t i = 0; i < strlen(sentence); i++) {
    if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
      charactersChecked[sentence[i] - 'A']++;
    } else if (sentence[i] >= 'a' && sentence[i] <= 'z') {
      charactersChecked[sentence[i] - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (*charactersChecked == 0) {
      free(charactersChecked);
      return false;
    }
    charactersChecked++;
  }
  free(charactersChecked);
  return true;
}

int main() {
  printf("%d", is_pangram("Meu Nome É Heitorabcdefghijklmnopqrstuvwxyz"));

  return 0;
}

#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
  char *cypher = (char *)malloc(sizeof(char) * strlen(text));
  char *pointer = cypher;

  while (*text) {
    if (*text >= 'A' && *text <= 'Z') {
      *cypher = ((*text - 'A') + shift_key) % 26 + 'A';
    } else if (*text >= 'a' && *text <= 'z') {
      *cypher = ((*text - 'a') + shift_key) % 26 + 'a';
    } else {
      *cypher = *text;
    }
    text++;
    cypher++;
  }

  return pointer;
}

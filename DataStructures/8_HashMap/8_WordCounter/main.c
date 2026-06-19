#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash_fn(HashTable *h, void *key) {
  char *k = (char *)key;
  int base = 127;
  int hashVal = 0;
  while (*k != '\0') {
    hashVal = (hashVal * base + *k) % hash_table_size(h);
    k++;
  }

  return hashVal;
}

int stringcmp(void *a, void *b) { return strcmp((char *)a, (char *)b); }

int main() {
  Vector *keys = vector_construct();
  HashTable *h = hash_table_construct(31, hash_fn, stringcmp);

  int nIns;
  scanf("%d", &nIns);

  for (int i = 0; i < nIns; i++) {
    char *string = (char *)malloc(32 * sizeof(char));
    scanf("%s", string);
    int *v = (int *)hash_table_get(h, string);
    if (v != NULL) {
      *v = *v + 1;
    } else {
      int *val = (int *)malloc(sizeof(int));
      *val = 1;
      hash_table_set(h, string, val);
      vector_push_back(keys, string);
    }
  }
  vector_sort(keys, stringcmp);

  for (int i = 0; i < vector_size(keys); i++) {
    char *val = (char *)vector_get(keys, i);
    printf("%s %d\n", val, *(int *)hash_table_get(h, val));
  }

  vector_destroy(keys);
  hash_table_destroy(h);
  return 0;
}

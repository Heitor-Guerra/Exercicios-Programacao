#include <stdlib.h>

const int *binary_search(int value, const int *arr, size_t length) {
  size_t i;
  size_t start = 0;
  while (start < length) {
    i = (start + length) / 2;
    if (arr[i] > value) {
      length = i;
    }
    if (arr[i] < value) {
      start = i + 1;
    }
    if (arr[i] == value) {
      return &arr[i];
    }
  }
  return NULL;
}

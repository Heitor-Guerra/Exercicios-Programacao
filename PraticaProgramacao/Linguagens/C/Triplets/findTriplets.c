#include <stdlib.h>

typedef struct {
  int a, b, c;
} triplet_t;

typedef struct {
  size_t count;
  triplet_t triplets[];
} triplets_t;

triplets_t *triplets_with_sum(int sum) {
  triplets_t *triplets = malloc(sizeof(triplets_t) * sum);
  triplets->count = 0;
  for (int a = 1; a < sum; ++a) {
    for (int b = a; b < sum; ++b) {
      int c = sum - a - b;
      if (c * c == a * a + b * b) {
        triplets->triplets[triplets->count].a = a;
        triplets->triplets[triplets->count].b = b;
        triplets->triplets[triplets->count].c = c;
        triplets->count++;
      }
    }
  }
  return triplets;
}
void free_triplets(triplets_t *triplets) { free(triplets); }

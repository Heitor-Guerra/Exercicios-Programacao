#include "heap.h"
#include "vector.h"
#include <stdlib.h>

struct Heap {
  Vector *data;
  cmp_fn cmp;
};

#define INC_ALLOC 2

// Cria um heap vazio
Heap *heap_construct(cmp_fn cmp) {
  Heap *h = (Heap *)malloc(sizeof(Heap));
  h->data = vector_construct();
  h->cmp = cmp;
  return h;
}

// Libera memória do heap
void heap_destroy(Heap *h, void (*free_item)(void *)) {
  for (int i = 0; i < heap_size(h); i++) {
    free_item(vector_get(h->data, i));
  }

  vector_destroy(h->data);
  free(h);
}

void heapify_up(Heap *h, int i) {
  int parent = (i - 1) / 2;
  if (h->cmp(vector_get(h->data, i), vector_get(h->data, parent)) > 0) {
    vector_swap(h->data, i, parent);
    heapify_up(h, parent);
  }
}

// Insere um elemento no heap
void heap_push(Heap *h, data_type value) {
  vector_push_back(h->data, value);

  int i = vector_size(h->data) - 1;

  heapify_up(h, i);
}

void heap_print(Heap *p, void (*print)(void *)) {
  for (int i = 0; i < vector_size(p->data); i++) {
    print(vector_get(p->data, i));
  }
}

void heapify_down(Heap *h, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < vector_size(h->data) &&
      h->cmp(vector_get(h->data, left), vector_get(h->data, largest)) > 0) {
    largest = left;
  }

  if (right < vector_size(h->data) &&
      h->cmp(vector_get(h->data, right), vector_get(h->data, largest)) > 0) {
    largest = right;
  }

  if (largest != i) {
    vector_swap(h->data, i, largest);
    heapify_down(h, largest);
  }
}

// Remove e retorna o elemento de maior prioridade
data_type heap_pop(Heap *h) {
  if (heap_size(h) == 1) {
    return vector_pop_back(h->data);
  }

  data_type ret = vector_get(h->data, 0);
  vector_set(h->data, 0, vector_pop_back(h->data));

  int i = 0;

  heapify_down(h, i);

  return ret;
}

// Retorna o número de elementos
int heap_size(Heap *h) { return vector_size(h->data); }

// Verifica se está vazio
int heap_empty(Heap *h) { return vector_size(h->data) == 0; }

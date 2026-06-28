#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_ALLOC 2

typedef int data_type;

struct Deque {
  data_type *data;
  int size;
  int alloc;
  int start;
  int end;
};

Deque *deque_construct() {
  Deque *d = (Deque *)malloc(sizeof(Deque));
  d->size = 0;
  d->end = 0;
  d->start = 0;
  d->alloc = TAM_ALLOC;
  d->data = (data_type *)malloc(d->alloc * sizeof(data_type));

  return d;
}

void deque_realloc(Deque *d) {
  int alloc = d->alloc * TAM_ALLOC;
  data_type *newData = (data_type *)malloc(alloc * sizeof(data_type));

  for (int i = 0; i < d->size; i++) {
    int pos = (d->start + i) % d->alloc;
    newData[i] = d->data[pos];
  }
  free(d->data);
  d->data = newData;
  d->alloc = alloc;
  d->end = d->size;
  d->start = 0;
}

void deque_push_back(Deque *f, data_type item) {
  if (f->alloc == f->size) {
    deque_realloc(f);
  }
  f->data[f->end] = item;
  f->end++;
  f->end %= f->alloc;
  f->size++;
}

void deque_push_front(Deque *f, data_type item) {
  if (f->alloc == f->size) {
    deque_realloc(f);
  }
  f->start += (f->alloc - 1);
  f->start %= f->alloc;
  f->data[f->start] = item;
  f->size++;
}

data_type deque_pop_back(Deque *f) {
  if (f->size == 0) {
    printf("FILA VAZIA");
    return -1;
  }
  f->end = (f->end + f->alloc - 1) % f->alloc;
  data_type item = f->data[f->end];
  f->size--;
  return item;
}

data_type deque_pop_front(Deque *f) {
  if (f->size == 0) {
    printf("FILA VAZIA");
    return -1;
  }
  data_type item = f->data[f->start];
  f->start = (f->start + 1) % f->alloc;
  f->size--;
  return item;
}

void deque_destroy(Deque *f) {
  if (f != NULL) {
    free(f->data);
    free(f);
  }
}

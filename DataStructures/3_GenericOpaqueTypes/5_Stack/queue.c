#include "queue.h"
#include "vector.h"
#include <stdlib.h>

struct queue {
  Vector *v;
};

Queue *queue_construct() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->v = vector_construct();
  return q;
}

int queue_size(Queue *q) { return vector_size(q->v); }

void queue_enqueue(Queue *q, data_type val) { vector_push_back(q->v, val); }

data_type queue_dequeue(Queue *q) { return vector_pop_front(q->v); }

void queue_destroy(Queue *q) {
  vector_destroy(q->v);
  free(q);
}

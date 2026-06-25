#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef void *data_type;

struct Queue {
  data_type *data;
  int first;
  int last;
  int size;
  int alloc;
};

// Create an queue
Queue *queue_constructor(int max_capacity) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->data = (data_type *)malloc(max_capacity * sizeof(data_type));
  q->first = 0;
  q->last = 0;
  q->size = 0;
  q->alloc = max_capacity;

  return q;
}

// Add an element
void queue_add(Queue *queue, void *data) {
  if (queue_is_full(queue)) {
    return;
  }

  queue->data[queue->last] = data;
  queue->last++;
  queue->last %= queue->alloc;
  queue->size++;
}

// Remove the oldest element in the queue
void *queue_remove(Queue *queue) {
  if (queue_is_empty(queue)) {
    printf("FILA VAZIA\n");
    return NULL;
  }

  data_type ret = queue->data[queue->first];
  queue->first++;
  queue->first %= queue->alloc;
  queue->size--;

  return ret;
}

// Return the number of elements in the queue
int queue_size(Queue *queue) { return queue->size; }

// Return 1 if the queue is full and 0, otherwise
int queue_is_full(Queue *queue) { return queue->alloc == queue->size; }

// Return 1 if the queue is empty and 0, otherwise
int queue_is_empty(Queue *queue) { return queue->size == 0; }

// Free the data structure.
// IMPORTANT: the user of the lib is responsible for removing and freeing
// elements remaining in the queue. In the queue is not empty when the functions
// is called, the function will not release them.
void queue_destroy(Queue *queue) {
  if (!queue_is_empty(queue)) {
    return;
  }
  free(queue->data);
  free(queue);
}

#ifndef QUEUE_H
#define QUEUE_H

#include "vector.h"

typedef struct queue Queue;

Queue *queue_construct();

int queue_size(Queue *q);

void queue_enqueue(Queue *q, data_type val);

data_type queue_dequeue(Queue *q);

void queue_destroy(Queue *q);

#endif

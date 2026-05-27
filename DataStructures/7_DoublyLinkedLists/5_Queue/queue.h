#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "list.h"
typedef struct Queue Queue;

Queue* queue_construct();

int queue_size(Queue* s);

void queue_push(Queue* s, data_type val);

data_type queue_pop(Queue* s);

void queue_destroy(Queue* s);

#endif
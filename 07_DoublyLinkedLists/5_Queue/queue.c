#include "queue.h"
#include <stdlib.h>

struct Queue {
    List * l;
};

Queue* queue_construct() {
    Queue* s = (Queue*)malloc(sizeof(Queue));
    s->l = list_construct();

    return s;
}

int queue_size(Queue* s) {
    return list_size(s->l);
}

void queue_push(Queue* s, data_type val) {
    list_push_front(s->l, val);
}

data_type queue_pop(Queue* s) {
    return list_pop_back(s->l);
}

void queue_destroy(Queue* s) {
    list_destroy(s->l);
    free(s);
}
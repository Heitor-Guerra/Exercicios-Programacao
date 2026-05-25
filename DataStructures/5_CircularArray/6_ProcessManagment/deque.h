#ifndef _DEQUE_H
#define _DEQUE_H

typedef struct Deque Deque;
typedef void* data_type;

Deque* deque_construct();

int deque_size(Deque* d);

void deque_push_back(Deque* d, data_type item);

void deque_push_front(Deque* d, data_type item);

data_type deque_pop_back(Deque* d);

data_type deque_pop_front(Deque* d);

data_type deque_get(Deque* d, int i);

void deque_destroy(Deque* d);

#endif
#include "priority_queue_vector.h"
#include "vector.h"
#include <stdlib.h>

struct PriorityQueue{
    Vector* v;
    int (*cmp_fn)(const void *, const void *);
};

PriorityQueue *pq_constructor(int cmp_fn(const void *, const void *)) {
    PriorityQueue* q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    q->cmp_fn = cmp_fn;
    q->v = vector_construct();

    return q;
}

void pq_push(PriorityQueue *pq, void *data) {
    for(int i = 0; i < pq_size(pq); i++) {
        if(pq->cmp_fn(data, vector_get(pq->v, i)) >= 0) {
            vector_insert(pq->v, i, data);
            return;
        }
    }
    vector_push_back(pq->v, data);
}

void *pq_pop(PriorityQueue *pq) {
    return vector_pop_front(pq->v);
}

int pq_size(PriorityQueue *pq) {
    return vector_size(pq->v);
}

void pq_destroy(PriorityQueue *pq) {
    vector_destroy(pq->v);
    free(pq);
}
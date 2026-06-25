#include "deque.h"
#include <stdlib.h>
#include <stdio.h>

#define ALLOC_INC 2

struct Deque {
    data_type* data;
    int size;
    int alloc;
    int start;
    int end;
};

void deque_realloc(Deque* d) {
    d->alloc *= ALLOC_INC;
    data_type* newData = (data_type*)malloc(d->alloc*sizeof(data_type));
    if(newData == NULL) {
        printf("Erro na realocacao do deque");
        exit(1);
    }

    for(int i = 0; i < d->size; i++) {
        newData[i] = d->data[(d->start+i)%d->size];
    }
    free(d->data);
    d->data = newData;
    d->start = 0;
    d->end = d->size;
}

/////////////////////


Deque* deque_construct() {
    Deque* d = (Deque*)malloc(sizeof(Deque));
    if(d == NULL) {
        printf("Erro na alocacao do deque");
        exit(1);
    }
    d->end = 0;
    d->start = 0;
    d->size = 0;
    d->alloc = ALLOC_INC;
    d->data = (data_type *)malloc(d->alloc*sizeof(data_type));
    if(d->data == NULL) {
        printf("Erro na alocacao do deque");
        exit(1);
    }

    return d;
}

int deque_size(Deque* d) {
    return d->size;
}

void deque_push_back(Deque* d, data_type item) {
    if(d->size == d->alloc) {
        deque_realloc(d);
    }

    d->data[d->end] = item;
    d->end = (d->end+1)%d->alloc;
    d->size++;
}

void deque_push_front(Deque* d, data_type item) {
    if(d->size == d->alloc) {
        deque_realloc(d);
    }
    d->start = (d->start+d->alloc-1) %d->alloc;
    d->data[d->start] = item;
    d->size++;
}

data_type deque_pop_back(Deque* d) {
    if(d->size <= 0) {
        printf("Deque Vazio");
        return NULL;
    }
    d->end = (d->end+d->alloc-1)%d->alloc;
    d->size--;
    return d->data[d->end];
}

data_type deque_pop_front(Deque* d) {
    if(d->size <= 0) {
        printf("Deque Vazio");
        return NULL;
    }
    data_type temp = d->data[d->start];
    d->start = (d->start+1)%d->alloc;
    d->size--;
    return temp;
}

data_type deque_get(Deque* d, int i) {
    if(i >= d->size) {
        return NULL;
    }
    return d->data[(d->start+i)% d->alloc];
}

void deque_destroy(Deque* d) {
    if(d != NULL) {
        free(d->data);
        free(d);
    }
}
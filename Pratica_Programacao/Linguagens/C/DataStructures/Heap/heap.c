#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

struct Heap {
    Vector* data;
    compare_pt compare;
};

void heapify_up(Heap* h, int i) {
    int father = (i - 1)/2;
    if(h->compare(vector_get(h->data, i), vector_get(h->data, father)) > 0) {
        vector_swap(h->data, i, father);
        heapify_up(h, father);
    }
}

void heapify_down(Heap* h, int i) {
    int left = i*2 + 1;
    int right = i*2 + 2;

    int largest = i;
    if(left < vector_size(h->data) && h->compare(vector_get(h->data, left), vector_get(h->data, largest)) > 0) {
        largest = left;
    }
    if(right < vector_size(h->data) && h->compare(vector_get(h->data, right), vector_get(h->data, largest)) > 0) {
        largest = right;
    }

    if(largest != i) {
        vector_swap(h->data, i, largest);
        heapify_down(h, largest);
    }
}


//////////////////////////


Heap* heap_construct(compare_pt compare) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    if(h == NULL) {
        printf("Erro na alocacao do heap");
        exit(1);
    }
    h->compare = compare;
    h->data = vector_construct();

    return h;
}

int heap_size(Heap* h) {
    return vector_size(h->data);
}

void heap_push(Heap* h, data_type item) {
    vector_push_back(h->data, item);

    heapify_up(h, vector_size(h->data)-1);
}

data_type heap_pop(Heap* h) {
    if (vector_size(h->data) <= 1) {
        return vector_pop_back(h->data);
    }

    data_type item = vector_get(h->data, 0);
    vector_set(h->data, 0, vector_pop_back(h->data));
    heapify_down(h, 0);

    return item;
}

data_type heap_get_max(Heap* h) {
    return vector_get(h->data, 0);
}

void heap_destroy(Heap* h) {
    if(h != NULL) {
        vector_destroy(h->data);
        free(h);
    }
}
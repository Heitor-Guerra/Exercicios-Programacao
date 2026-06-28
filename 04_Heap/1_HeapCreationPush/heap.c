#include "heap.h"
#include "vector.h"
#include <stdlib.h>

struct Heap {
    Vector *data;
    cmp_fn cmp;
};

#define INC_ALLOC 2

// Cria um heap vazio
Heap *heap_construct(cmp_fn cmp) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->data = vector_construct();
    h->cmp = cmp;
    return h;
}

// Libera memória do heap
void heap_destroy(Heap *h, void (*free_item)(void *)) {
    for(int i = 0; i < heap_size(h); i++) {
        free_item(vector_get(h->data, i));
    }

    vector_destroy(h->data);
    free(h);
}

// Insere um elemento no heap
void heap_push(Heap *h, data_type value) {
    vector_push_back(h->data, value);

    int i = vector_size(h->data) - 1;

    while(i > 0) {
        int pai = (i-1)/2;

        if(h->cmp(vector_get(h->data, i), vector_get(h->data, pai)) > 0) {
            vector_swap(h->data, i, pai);
            i = pai;
        } else {
            break;
        }
    }
}

void heap_print(Heap* p, void (*print)(void *)) {
    for(int i = 0; i < vector_size(p->data); i++) {
        print(vector_get(p->data, i));
    }
}

// Remove e retorna o elemento de maior prioridade
data_type heap_pop(Heap *h) {
    if(heap_size(h) == 1) {
        return vector_pop_back(h->data);
    }

    data_type ret = vector_get(h->data, 0);
    vector_set(h->data, 0, vector_pop_back(h->data));

    int i = 0;

    while(1) {
        int filhoE = i*2 + 1;
        int filhoD = i*2 + 2;


        if(filhoE > heap_size(h)-1) {
            break;
        }
        data_type valueFilhoE = vector_get(h->data, filhoE);

        if(filhoD > heap_size(h)-1) {
            if(h->cmp(vector_get(h->data, i), valueFilhoE) < 0) {
                vector_swap(h->data, i, filhoE);
            }
            break;
        }
        data_type valueFilhoD = vector_get(h->data, filhoD);
        

        int cmp = h->cmp(valueFilhoE, valueFilhoD);
        if(h->cmp(vector_get(h->data, i), valueFilhoE) < 0 && cmp >= 0) {
            vector_swap(h->data, i, filhoE);
            i = filhoE;
        } else if(h->cmp(vector_get(h->data, i), valueFilhoD) < 0 && cmp <= 0) {
            vector_swap(h->data, i, filhoD);
            i = filhoD;
        } else {
            break;
        }
    }

    return ret;
}

// Retorna o número de elementos
int heap_size(Heap *h) {
    return vector_size(h->data);
}

// Verifica se está vazio
int heap_empty(Heap *h) {
    return vector_size(h->data) == 0;
}

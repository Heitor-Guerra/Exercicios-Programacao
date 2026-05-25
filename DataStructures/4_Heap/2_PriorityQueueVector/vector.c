#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 2;

Vector *vector_construct() {
    Vector * v = (Vector*)malloc(sizeof(Vector));
    v->size = 0;
    v->allocated = SIZE;
    v->data = (data_type*)malloc(v->allocated*sizeof(data_type));

    return v;
}

void vector_push_back(Vector *v, data_type val) {
    if(v->size == v->allocated) {
        v->allocated *= SIZE;
        v->data = (data_type*)realloc(v->data, v->allocated*sizeof(data_type));
    }

    v->data[v->size] = val;
    v->size++;
}

data_type vector_get(Vector *v, int i) {
    if(v->size <= i) {
        perror("Index out of bounds");
        exit(1);
    }
    return v->data[i];
}   

void vector_set(Vector *v, int i, data_type val) {
    if(v->size <= i) {
        perror("Index out of bounds");
        exit(1);
    }
    v->data[i] = val;
}

int vector_size(Vector *v) {
    return v->size;
}

int vector_find(Vector *v, data_type val, compare_pt compare) {
    for(int i = 0; i < v->size; i++) {
        if(compare(v->data[i], val) == 0) {
            return i;
        }
    }
    return -1;
}

// Troca os elementos das posiÃ§Ãµes i e j (i vira j e j vira i)
void vector_swap(Vector *v, int i, int j) {
    data_type temp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = temp;
}

// Remove o i-Ã©simo elemento do vetor.
data_type vector_remove(Vector *v, int i) {
    data_type temp = vector_get(v, i);
    
    for(int j = i; j < v->size-1; j++) {
        v->data[j] = v->data[j+1];
    }
    v->size--;

    return temp;
}

// Insere o elemento na i-esima posicao
void vector_insert(Vector *v, int i, data_type val) {
    if(v->allocated == v->size) {
        v->allocated *= SIZE;
        v->data = (data_type*)realloc(v->data, v->allocated*sizeof(data_type));
    }


    for(int j = v->size-1; j >= i; j--) {
        v->data[j+1] = v->data[j];
    }
    v->data[i] = val;
    v->size++;
}

// Remove o primeiro elemento
data_type vector_pop_front(Vector *v) {
    return vector_remove(v, 0);
}

// Remove o ultimo elemento
data_type vector_pop_back(Vector *v) {
    return vector_remove(v, v->size-1);
}

// Ordena o vetor in-place (sem criar um novo vetor)
void vector_sort(Vector *v, compare_pt compare) {
    for(int i = 1; i < v->size; i++) {
        for(int j = 0; j < v->size-1; j++) {
            if(compare(v->data[j], v->data[j+1]) > 0) {
                vector_swap(v, j, j+1);
            }
        }
    }
}

// Retorna o indice de val usando busca binaria. Retorna -1 se nao encontrado.
int vector_binary_search(Vector *v, data_type val, compare_pt compare) {
    int start = 0, end = v->size-1;

    while(start <= end) {
        int mid = (start+end)/2;
        
        if(compare(v->data[mid], val) > 0) {
            end = mid-1;
            continue;
        } else if(compare(v->data[mid], val) < 0) {
            start = mid+1;
            continue;
        }

        return mid;
    }
    return -1;
}

// Inverte o vetor in-place (sem criar um novo vetor)
void vector_reverse(Vector *v) {
    for(int i = 0; i < v->size/2; i++) {
        vector_swap(v, i, v->size-i-1);
    }
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}
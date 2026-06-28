#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define ALLOC_INC 2

struct Vector {
    data_type * data;
    int size;
    int alloc;
};

void vector_realloc(Vector* v){
    if(v->size == v->alloc) {
        v->alloc *= ALLOC_INC;
        v->data = (data_type*)realloc(v->data, v->alloc*sizeof(data_type));
        if(v->data == NULL) {
            printf("Erro na realocacao do vector");
            exit(1);
        }
    }
}


///////////////////////////


Vector* vector_construct() {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    if(v == NULL) {
        printf("Erro na alocacao do vector");
        exit(1);
    }
    v->alloc = ALLOC_INC;
    v->size = 0;
    v->data = (data_type*)malloc(v->alloc*sizeof(data_type));
    if(v->data == NULL) {
        printf("Erro na alocacao do vector");
        exit(1);
    }

    return v;
}

int vector_size(Vector* v) {
    return v->size;
}

void vector_remove(Vector* v, int pos) {
    v->size--;
    for(int i = pos; i < vector_size(v); i++) {
        v->data[i] = v->data[i+1];
    }
}

void vector_push_back(Vector* v, data_type item) {
    vector_realloc(v);
    v->data[v->size] = item;
    v->size++;
}

data_type vector_pop_back(Vector* v) {
    if(v->size <= 0) {
        printf("O vector esta vazio");
        return NULL;
    }
    v->size--;
    return v->data[v->size];
}

data_type vector_get(Vector* v, int i) {
    if(i < 0 || i >= v->size) {
        printf("Indice fora da fronteira");
        return NULL;
    }
    return v->data[i];
}

void vector_set(Vector* v, int i, data_type item) {
    if(i < 0 || i >= v->size) {
        printf("Indice fora da fronteira");
        return;
    }
    v->data[i] = item;
}

void vector_swap(Vector* v, int i, int j) {
    if(i < 0 || i >= v->size || j < 0 || j >= v->size) {
        printf("Indice fora da fronteira");
        return;
    }
    data_type temp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = temp;
}


void vector_destroy(Vector* v) {
    if(v != NULL) {
        free(v->data);
        free(v);
    }
}
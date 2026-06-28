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

int vector_find(Vector *v, data_type val) {
    for(int i = 0; i < v->size; i++) {
        if(v->data[i] == val) {
            return i;
        }
    }
    return -1;
}


void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}
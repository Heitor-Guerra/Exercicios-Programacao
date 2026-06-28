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

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val) {
    if(v->size == v->allocated) {
        v->allocated *= SIZE;
        v->data = (data_type*)realloc(v->data, v->allocated*sizeof(data_type));
    }

    v->data[v->size] = val;
    v->size++;
}
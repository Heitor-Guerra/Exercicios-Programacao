#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *vector_construct() {
    Vector * v = (Vector*)malloc(sizeof(Vector));
    v->size = 0;
    v->allocated = 2;
    v->data = (data_type*)malloc(v->allocated*sizeof(data_type));

    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}
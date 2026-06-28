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



// Retorna o maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_max(Vector *v) {
    data_type max = v->data[0];
    for(int i = 0; i < v->size; i++) {
        if(v->data[i] > max) {
            max = v->data[i];
        }
    }
    return max;
}

// Retorna o menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_min(Vector *v) {
    data_type min = v->data[0];
    for(int i = 0; i < v->size; i++) {
        if(v->data[i] < min) {
            min = v->data[i];
        }
    }
    return min;
}

// Retorna o Ã­ndice do maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmax(Vector *v) {
    data_type max = v->data[0];
    data_type maxI = 0;
    for(int i = 0; i < v->size; i++) {
        if(v->data[i] > max) {
            max = v->data[i];
            maxI = i;
        }
    }
    return maxI; 
}

// Retorna o Ã­ndice do menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmin(Vector *v) {
    data_type min = v->data[0];
    data_type minI = 0;
    for(int i = 0; i < v->size; i++) {
        if(v->data[i] < min) {
            min = v->data[i];
            minI = i;
        }
    }
    return minI; 
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}
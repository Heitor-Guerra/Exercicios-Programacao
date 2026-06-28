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

// Troca os elementos das posiÃ§Ãµes i e j (i vira j e j vira i)
void vector_swap(Vector *v, int i, int j) {
    data_type temp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = temp;
}

// Remove o i-Ã©simo elemento do vetor.
data_type vector_remove(Vector *v, int i) {
    int temp = vector_get(v, i);
    
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
void vector_sort(Vector *v) {
    for(int i = 1; i < v->size; i++) {
        for(int j = 0; j < v->size-1; j++) {
            if(v->data[j] > v->data[j+1]) {
                vector_swap(v, j, j+1);
            }
        }
    }
}

// Retorna o indice de val usando busca binaria. Retorna -1 se nao encontrado.
int vector_binary_search(Vector *v, data_type val);

// Inverte o vetor in-place (sem criar um novo vetor)
void vector_reverse(Vector *v) {

}

// Cria uma cÃ³pia do vector e dos valores de seus atributos.
Vector *vector_copy(Vector *v);

// Remove todos os elementos de v
void vector_clear(Vector *v) {

}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}
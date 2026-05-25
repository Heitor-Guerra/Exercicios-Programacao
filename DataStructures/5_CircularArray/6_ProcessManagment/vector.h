#ifndef _VECTOR_H
#define _VECTOR_H

typedef struct Vector Vector;
typedef void* data_type;
typedef int (*compare_pt)(const void* a, const void* b);

Vector* vector_construct();

int vector_size(Vector* v);

void vector_remove(Vector* v, int pos);

void vector_push_back(Vector* v, data_type item);

data_type vector_pop_back(Vector* v);

data_type vector_get(Vector* v, int i);

void vector_set(Vector* v, int i, data_type item);

void vector_swap(Vector* v, int i, int j);

void vector_destroy(Vector* v);


#endif
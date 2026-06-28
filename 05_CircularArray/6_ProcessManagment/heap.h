#ifndef _HEAP_H
#define _HEAP_H

typedef struct Heap Heap;
typedef void* data_type;
typedef int (*compare_pt)(const void* a, const void* b);

Heap* heap_construct(compare_pt compare);

int heap_size(Heap* h);

void heap_push(Heap* h, data_type item);

data_type heap_pop(Heap* h);

data_type heap_get_max(Heap* h);

void heap_destroy(Heap* h);

#endif
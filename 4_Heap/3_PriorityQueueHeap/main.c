#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Processo {
    char nome[32];
    char categoria[32];
    int id;
    int prioridade;
} Processo;

Processo* criaProcesso(char *nome, char *categoria, int id, int prioridade) {
    Processo *p = (Processo*)malloc(sizeof(Processo));
    strcpy(p->nome, nome);
    strcpy(p->categoria, categoria);
    p->id = id;
    p->prioridade = prioridade;

    return p;
}

void destroyProcesso(void* p) {
    free(p);
}

int comparaProcesso(void* p1, void* p2) {
    Processo* pr1 = (Processo*)p1;
    Processo* pr2 = (Processo*)p2;
    return pr1->prioridade - pr2->prioridade;
}

void printProcesso(void* pr) {
    Processo* p = (Processo*)pr;
    printf("\n%s %s %d %d\n", p->nome, p->categoria, p->id, p->prioridade);
}


int main() {
    int n;
    scanf("%d", &n);
    Heap* heap = heap_construct(comparaProcesso);
    
    for(int i = 0; i < n; i++) {
        char nome[32];
        char categoria[32];
        int id;
        int prioridade;
        scanf("\n%s %s %d %d", nome, categoria, &id, &prioridade);

        heap_push(heap, criaProcesso(nome, categoria, id, prioridade));
    }

    printf("\n\n");
    for(int i = 0; i < n; i++) {
        Processo* p = (Processo*)heap_pop(heap);
        printProcesso(p);
        destroyProcesso(p);
    }

    heap_destroy(heap, destroyProcesso);

    return 0;
}
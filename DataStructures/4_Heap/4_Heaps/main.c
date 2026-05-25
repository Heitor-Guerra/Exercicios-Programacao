#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[32];
    int idade;
} Paciente;

Paciente* criaPaciente(char *nome, int idade) {
    Paciente *p = (Paciente*)malloc(sizeof(Paciente));
    strcpy(p->nome, nome);
    p->idade = idade;

    return p;
}

void destroyPaciente(void* p) {
    free(p);
}

int comparaPaciente(void* p1, void* p2) {
    Paciente* pr1 = (Paciente*)p1;
    Paciente* pr2 = (Paciente*)p2;
    return pr1->idade - pr2->idade;
}

void printPaciente(void* pr) {
    Paciente* p = (Paciente*)pr;
    printf("%s %d\n", p->nome, p->idade);
}


int main() {
    int n;
    scanf("%d", &n);
    Heap* heap = heap_construct(comparaPaciente);
    
    for(int i = 0; i < n; i++) {
        char opcao[11];
        scanf("\n%s", opcao);
        if(strcmp(opcao, "ADICIONAR") == 0) {
            char nome[32];
            int prioridade;
            scanf("%s %d", nome, &prioridade);
            heap_push(heap, criaPaciente(nome, prioridade));
        } else if (strcmp(opcao, "CHAMAR") == 0) {
            Paciente* p = (Paciente*)heap_pop(heap);
            printPaciente(p);
            destroyPaciente(p);
        }
    }

    int size = heap_size(heap);
    for(int i = 0; i < size; i++) {
        Paciente* p = (Paciente*)heap_pop(heap);
        printPaciente(p);
        destroyPaciente(p);
    }

    heap_destroy(heap, destroyPaciente);

    return 0;
}
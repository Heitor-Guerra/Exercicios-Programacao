#include "program.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Program {
    char nome[65];
    char tipo[5];
    int prio;
    int carga;
    int inicio;
    int fim;
};

Program *program_construct(char *nome, char *tipo, int prio, int carga, int inicio) {
    Program* p = (Program*)malloc(sizeof(Program));
    if(p == NULL) {
        printf("Erro na alocacao do programa");
        exit(1);
    }
    strcpy(p->nome, nome);
    strcpy(p->tipo, tipo);
    p->prio = prio;
    p->carga = carga;
    p->inicio = inicio;
    p->fim = -1;

    return p;
}

char* program_get_name(Program* p) {
    return p->nome;
}
char* program_get_tipo(Program* p) {
    return p->tipo;
}
int program_get_prio(Program* p) {
    return p->prio;
}
int program_get_carga(Program* p) {
    return p->carga;
}
int program_get_inicio(Program* p) {
    return p->inicio;
}
int program_get_fim(Program* p) {
    return p->fim;
}


void program_carga_decrement(Program* p) {
    p->carga--;
}
void program_set_fim(Program* p, int fim) {
    p->fim = fim;
}

int program_compare(const void* a, const void* b) {
    Program* pa = (Program*)a;
    Program* pb = (Program*)b;

    int diff = pa->prio - pb->prio;
    if(diff != 0) {
        return diff;
    }

    if(strcmp(pa->tipo, "SO") == 0) {
        int diff2 = pb->carga - pa->carga;
        if(diff2 != 0) {
            return diff2;
        }
    } else if (strcmp(pa->tipo, "USER") == 0) {
        int diff2 = pb->fim - pa->fim;
        if(diff2 != 0) {
            return diff2;
        }
    }
    return strcmp(pb->nome, pa->nome);
}

void program_destroy(Program* p) {
    if(p != NULL) {
        free(p);
    }
}
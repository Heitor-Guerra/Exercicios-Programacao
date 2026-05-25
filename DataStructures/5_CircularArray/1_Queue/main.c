#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atendimento.h"

#define ALLOC_TAM 10

int main() {
    Atendimento* fila[ALLOC_TAM];
    int inicio = 0, fim = 0, tam = 0;    
    int comandos;
    char comando[10];

    scanf("%d", &comandos);
    for(int i = 0; i < comandos; i++) {
        scanf("\n%s", comando);
        if(strcmp(comando, "CHAMAR") == 0 && tam != 0) {
            Atendimento *a = fila[inicio];
            inicio++;
            inicio %= ALLOC_TAM;
            tam--;
            printNomeAtendimento(a);
            destroiAtendimento(a);
        } else if (strcmp(comando, "ADICIONAR") == 0 && tam != ALLOC_TAM) {
            Atendimento *a = leAtendimento();
            fila[fim] = a;
            fim++;
            fim %= ALLOC_TAM;
            tam++;
        } else if(tam == 0) {
            printf("FILA VAZIA\n");
        } else {
            printf("FILA CHEIA\n");
            scanf("%*s %*s");
        }
    }


    for(int i = 0; i < tam; i++) {
        Atendimento *a = fila[inicio];
        destroiAtendimento(a);
        inicio++;
        inicio %= ALLOC_TAM;
    }

    return 0;
}
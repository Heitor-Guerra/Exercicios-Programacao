#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frame.h"

#define ALLOC_TAM 20

int main() {
    Frame* buffer[ALLOC_TAM];
    int inicio = 0, fim = 0, tam = 0;

    int comandos;
    char comando[10];

    scanf("%d", &comandos);
    for(int i = 0; i < comandos; i++) {
        scanf("\n%s", comando);
        if(strcmp(comando, "PLAY") == 0 && tam >= 5) {
            for(int j = 0; j < 5; j++) {
                Frame *a = buffer[inicio];
                inicio++;
                inicio %= ALLOC_TAM;
                tam--;
                printFrame(a);
                destroiFrame(a);
            }
        } else if (strcmp(comando, "ADICIONAR") == 0 && tam != ALLOC_TAM) {
            Frame *a = leFrame();
            buffer[fim] = a;
            fim++;
            fim %= ALLOC_TAM;
            tam++;
        } else if(tam < 5) {
            printf("AGUARDE\n");
        } else {
            printf("FILA CHEIA\n");
            scanf("%*s %*d %*f");
        }
    }


    for(int i = 0; i < tam; i++) {
        Frame *a = buffer[inicio];
        destroiFrame(a);
        inicio++;
        inicio %= ALLOC_TAM;
    }

    return 0;
}
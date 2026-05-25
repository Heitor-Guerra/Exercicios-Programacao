#include <stdio.h>

void InicializaVetor(int vetor[], int tam) {
    int i = 0;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
}

int VerificaAContidoB(int vetorA[], int vetorB[], int tamA, int tamB) {
    int i, j, condicao = 0;
    for(i = 0; i < tamA; i++) {
        for(j = 0; j < tamB; j++) {
            if(vetorA[i] == vetorB[j]) {
                condicao++;
                break;
            }
        }
    }
    return condicao;
}

int main() {
    int tamA, tamB, caso;
    scanf("%d", &tamA);
    int vetorA[tamA];
    InicializaVetor(vetorA, tamA);
    scanf("%d", &tamB);
    int vetorB[tamB];
    InicializaVetor(vetorB, tamB);

    caso = VerificaAContidoB(vetorA, vetorB, tamA, tamB);
    if(caso == tamA) {
        printf("TODOS");
    }
    else if(caso == 0) {
        printf("NENHUM");
    }
    else {
        printf("PARCIAL");
    }

    return 0;
}
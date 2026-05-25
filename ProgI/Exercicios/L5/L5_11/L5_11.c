#include <stdio.h>

void InicializaVetor(int vetor[], int tam) {
    int i = 0;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
}

void OrdenaCrescente(int vet[], int qtd) {
    int i, j, aux = 0, menor, menorPos;
    for(i = 0; i < qtd; i++) {
        menor = vet[i];
        menorPos = i;
        for(j = i; j < qtd; j++) {
            if(vet[j] < menor) {
                menor = vet[j];
                menorPos = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[menorPos];
        vet[menorPos] = aux;
    }
}

int main() {
    int tamA, tamB, i = 0, j = 0;

    scanf("%d", &tamA);
    int sequenciaA[tamA];
    InicializaVetor(sequenciaA, tamA);
    scanf("%d", &tamB);
    int sequenciaB[tamB];
    InicializaVetor(sequenciaB, tamB);

    OrdenaCrescente(sequenciaA, tamA);
    OrdenaCrescente(sequenciaB, tamB);

    while(i < tamA && j < tamB) {
        if(sequenciaA[i] <= sequenciaB[j]) {
            printf("A");
            i++;
        }
        else {
            printf("B");
            j++;
        }
    }
    for(i; i < tamA; i++) {
        printf("A");
    }
    for(j; j < tamB; j++) {
        printf("B");
    }

    return 0;
}
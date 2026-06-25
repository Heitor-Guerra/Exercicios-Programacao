#include <stdio.h>

void InicializaVetor(int vetor[], int tam) {
    int i = 0;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
}

void InverteVetor(int vet[], int qtd) {
    int i, aux;
    for(i = 0; i < qtd/2; i++) {
        aux = vet[i];
        vet[i] = vet[qtd-i-1];
        vet[qtd-i-1] = aux;
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd) {
    int i;
    printf("{");
    for(i = 0; i < qtd; i++) {
        if(i == (qtd - 1)) {
            printf("%d", vet[i]);
        }
        else {
            printf("%d, ", vet[i]);
        }
    }
    printf("}");
}

int main() {
    int tam, i = 1;
    scanf("%d", &tam);
    int sequencia[tam];
    InicializaVetor(sequencia, tam);

    InverteVetor(sequencia, tam);
    ImprimeDadosDoVetor(sequencia, tam);

    return 0;
}
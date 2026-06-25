#include <stdio.h>

void InicializaVetor(int vetor[], int tam) {
    int i = 0;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
}

void TrocaParEImpar(int vet[], int qtd) {
    int i, aux;
    for(i = 0; i < qtd; i++) {
        if(i%2 == 1) {
            aux = vet[i];
            vet[i] = vet[i-1];
            vet[i-1] = aux;
        }
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

    TrocaParEImpar(sequencia, tam);
    ImprimeDadosDoVetor(sequencia, tam);

    return 0;
}
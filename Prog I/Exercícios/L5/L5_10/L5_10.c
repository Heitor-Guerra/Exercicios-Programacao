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

    OrdenaCrescente(sequencia, tam);
    ImprimeDadosDoVetor(sequencia, tam);

    return 0;
}
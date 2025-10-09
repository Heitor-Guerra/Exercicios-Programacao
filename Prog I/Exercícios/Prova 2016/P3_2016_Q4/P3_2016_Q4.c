#include <stdio.h>

void LeVetor(int vet[], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

int QuantosMaiorQueA(int vet[], int tam, int num) {
    int i, cont = 0;
    for(i = 0; i < tam; i++) {
        if(vet[i] > num) {
            cont++;
        }
    }
    return cont;
}

int main() {
    int qtdCasos = 0, i, j;
    int tamSequencia;
    scanf("%d", &qtdCasos);

    for(i = 0; i < qtdCasos; i++) {
        scanf("%d", &tamSequencia);
        int sequencia[tamSequencia];
        LeVetor(sequencia, tamSequencia);
        for(j = 0; j < tamSequencia; j++) {
            printf("%d ", QuantosMaiorQueA(sequencia, tamSequencia, sequencia[j]));
        }
        printf("\n");
    }
    return 0;
}
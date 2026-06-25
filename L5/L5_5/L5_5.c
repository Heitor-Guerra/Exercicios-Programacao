#include <stdio.h>

void InicializaVetor(int vetor[], int tam) {
    int i = 0;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
}

int main() {
    int tam, i = 1, numDesejado = 0;
    scanf("%d %d", &numDesejado, &tam);
    int numeros[tam];
    InicializaVetor(numeros, tam);

    for(i = 0; i < tam; i++) {
        if (numeros[i] == numDesejado) {
            break;
        }
    }
    printf("RESP:%d", i);

    return 0;
}
#include <stdio.h>

void InicializaVetor(int vetor[], int tam) {
    int i = 0;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
}

int main() {
    int tam, i = 1, razao = 0;
    scanf("%d", &tam);
    int sequencia[tam];
    InicializaVetor(sequencia, tam);
    if(tam <= 1) {
        printf("NAO");
        return 0;
    }
    razao = sequencia[1] - sequencia[0];

    for(i = 1; i < tam; i++) {
        if((sequencia[i] - sequencia[i-1]) != razao) {
            printf("NAO");
            return 0;
        }
    }
    printf("RESP:%d", razao);

    return 0;
}
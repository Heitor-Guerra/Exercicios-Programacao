#include <stdio.h>

void LeVetor(int vet[]) {
    int i = 0;
    while(1) {
        scanf("%d", &vet[i]);
        if(vet[i] == -1) {
            break;
        }
        i++;
    }
}

void RealizaSoma(int vet1[], int vet2[], int res[]) {
    int i = 50, primeiroCharEInvalido = 1;
    int numDig1, numDig2;
    for(numDig1 = 0; vet1[numDig1+1] != -1; numDig1++) {}
    for(numDig2 = 0; vet2[numDig2+1] != -1; numDig2++) {}

    for(numDig1; numDig1 >= 0; numDig1--) {
        if(numDig2 >= 0) {
            res[i] = vet1[numDig1] + vet2[numDig2];
        }
        else{
            res[i] = vet1[numDig1];
        }

        if(res[i] > 9) {
            res[i] = res[i]%10;
            if(numDig1 > 0) {
                vet1[numDig1-1]++;
            }
            else{
                res[i-1] = 1;
                primeiroCharEInvalido = 0;
            }
        }
        numDig2--;
        i--;
    }
    for(i; i < 51; i++) {
        if(primeiroCharEInvalido) {
            primeiroCharEInvalido = 0;
            continue;
        }
        printf("%d", res[i]);
    }
    printf("\n");
}

int main() {
    int numPares, i;
    int num1[51];
    int num2[51];
    int resultado[51];
    scanf("%d", &numPares);

    for(i = 0; i < numPares; i++) {
        LeVetor(num1);
        LeVetor(num2);
        RealizaSoma(num1, num2, resultado);
    }


    return 0;
}
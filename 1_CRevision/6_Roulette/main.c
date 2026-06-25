#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int tamRoleta = 0, n = 0, numero;
    scanf("%d\n", &tamRoleta);
    scanf("%d\n", &n);

    int casaAtual = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d\n", &numero);
        casaAtual += numero;
        casaAtual %= tamRoleta;
    }

    printf("%d", casaAtual);

    return 0;
}
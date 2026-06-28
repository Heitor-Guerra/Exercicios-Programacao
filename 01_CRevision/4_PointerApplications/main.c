#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void maiorEMenor(int *array, int n, int *maior, int *menor) {
    for(int i = 0; i < n; i++) {
        if(array[i] <= *menor) {
            *menor = array[i];
        }
        if(array[i] >= *maior) {
            *maior = array[i];
        }
    }
}

int main() {
    int n, maior, menor;
    scanf("%d\n", &n);

    int *array = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", array+i);
    }

    maior = array[0];
    menor = array[0];
    maiorEMenor(array, n, &maior, &menor);

    printf("%d\n", menor);
    printf("%d\n", maior);  

    free(array);
    return 0;
}
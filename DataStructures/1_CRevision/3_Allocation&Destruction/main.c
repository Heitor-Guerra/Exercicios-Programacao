#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d\n", &n);

    int *array = (int*)malloc(n*sizeof(int));
    float media = 0, desvio = 0;


    for(int i = 0; i < n; i++) {
        scanf("%d\n", array+i);

        media += array[i];
    }
    media /= n;


    for(int i = 0; i < n; i++) {
        desvio += pow(array[i] - media, 2);
    }
    desvio /= (n-1);

    desvio = sqrt(desvio);

    printf("%.2f\n", media);
    printf("%.2f\n", desvio);


    free(array);
    return 0;
}
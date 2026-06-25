#include <stdio.h>

void LeVetor(int tam, int vet[]) {
    int i;
    for(i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}
 
int main() {
    int i;
    int num1, num2;

    scanf("%d", &num1);
    int seq1[num1];
    LeVetor(num1, seq1);

    scanf("%d", &num2);
    int seq2[num2];
    LeVetor(num2, seq2);

    printf("PARES:\n");
    for(i = 0; i < num1; i++) {
        printf("%d - %d\n", seq1[i], seq2[i%num2]);
    }

    return 0;
}
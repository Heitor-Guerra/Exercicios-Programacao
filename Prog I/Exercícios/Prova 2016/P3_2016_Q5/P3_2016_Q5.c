#include <stdio.h>

void TransformaEmMinusculo(char * string) {
    int i;
    for(i = 0; string[i] != '\0'; i++) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 'a' - 'A';
        }
    }
}

int VerificaConstrutibilidade(char * alvo, char * fonte) {
    int i, j = 0, letrasEncontradas = -1;
    for(i = 0; alvo[i] != '\0'; i++) {
        for(j; fonte[j] != '\0'; j++) {
            if(alvo[i] == fonte[j]) {
                j++;
                letrasEncontradas++;
                break;
            }
        }
        if(letrasEncontradas != i) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int qtdCasos = 0, i, j;
    char alvo[400];
    char fonte[400];
    scanf("%d", &qtdCasos);

    for(i = 0; i < qtdCasos; i++) {
        scanf("\n%s", alvo);
        TransformaEmMinusculo(alvo);
        scanf("%s", fonte);
        TransformaEmMinusculo(fonte);
        if(VerificaConstrutibilidade(alvo, fonte)) {
            printf("PODE!\n");
        }
        else {
            printf("NAO PODE!\n");
        }
    }
    return 0;
}
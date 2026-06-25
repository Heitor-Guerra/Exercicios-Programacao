#include <stdio.h>

void LeMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    int i, j;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void MultiplicaMatriz(int linha1, int coluna1, int matriz1[linha1][coluna1], int linha2, int coluna2, int matriz2[linha2][coluna2], int matrizR[linha1][coluna2]) {
    int i, j, k;
    int num;
    for(i = 0; i < linha1; i++) {
        for(j = 0; j < coluna2; j++) {
            num = 0;
            for(k = 0; k < coluna1; k++) {
                num += matriz1[i][k]*matriz2[k][j];
            }
            matrizR[i][j] = num;
        }
    }
}

void ImprimeMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    int i, j;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int numeroPares = 0, colunas1 = 0, linhas1 = 0, colunas2 = 0, linhas2 = 0;
    int n, i1, j1, i2, j2;

    scanf("%d", &numeroPares);

    for(n = 0; n < numeroPares; n++) {
        scanf("%d %d", &colunas1, &linhas1);
        int matriz1[linhas1][colunas1];
        LeMatriz(linhas1, colunas1, matriz1);
        scanf("%d %d", &colunas2, &linhas2);
        int matriz2[linhas2][colunas2];
        LeMatriz(linhas2, colunas2, matriz2);

        if(linhas2 != colunas1) {
            printf("IMPOSSIVEL\n\n");
            continue;
        }
        int matrizRes[linhas1][colunas2];
        MultiplicaMatriz(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizRes);
        ImprimeMatriz(linhas1, colunas2, matrizRes);
    }

    return 0;
}
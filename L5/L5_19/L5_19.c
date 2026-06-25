#include <stdio.h>

void LeMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    int i, j;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            scanf("%1d", &matriz[i][j]);
        }
    }
}

int ContaTerra(int linha, int coluna, int matriz[linha][coluna]) {
    int i, j, terra = 0;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            if(matriz[i][j] == 0) {
                terra++;
            }
        }
    }
    return terra;
}

void MareAvanca(int linha, int coluna, int matriz[linha][coluna], int matrizPosVerificada[linha][coluna]) {
    int i, j;

    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            if(matriz[i][j] == 1 && matrizPosVerificada[i][j] == 0) {
                if(i > 0 && matriz[i-1][j] == 0) {
                    matriz[i-1][j] = 1;
                    matrizPosVerificada[i-1][j] = 1;
                }
                if(j > 0 && matriz[i][j-1] == 0) {
                    matriz[i][j-1] = 1;
                    matrizPosVerificada[i][j-1] = 1;
                }
                if(i < linha - 1 && matriz[i+1][j] == 0) {
                    matriz[i+1][j] = 1;
                    matrizPosVerificada[i+1][j] = 1;
                }
                if(j < coluna - 1 && matriz[i][j+1] == 0) {
                    matriz[i][j+1] = 1;
                    matrizPosVerificada[i][j+1] = 1;
                }
            }
        }
    }
}

int main() {
    int horas = 0, linhas = 0, colunas = 0;
    int h, i, j;
    scanf("%d", &horas);
    scanf("%d %d", &colunas, &linhas);
    int matriz[linhas][colunas];
    int matrizPosVerificada[linhas][colunas];
    LeMatriz(linhas, colunas, matriz);

    printf("%d ", ContaTerra(linhas, colunas, matriz));
    for(h = 0; h < horas; h++) {
        for(i = 0; i < linhas; i++) {
            for(j = 0; j < colunas; j++) {
                matrizPosVerificada[i][j] = 0;
            }
        }
        MareAvanca(linhas, colunas, matriz, matrizPosVerificada);
    }
    printf("%d\n", ContaTerra(linhas, colunas, matriz));

    return 0;
}
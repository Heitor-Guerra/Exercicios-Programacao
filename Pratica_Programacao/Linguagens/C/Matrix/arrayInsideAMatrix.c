#include <stdio.h>

void LeMatriz(int linhas, int colunas, char matriz[linhas][colunas]) {
    int i, j;
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            scanf("%c", &matriz[i][j]);
        }
        scanf("%*[^\n]");
        scanf("%*c");
    }
}

int VerificaHorizontal(int linhas, int colunas, char matriz[linhas][colunas], int qtdX) {
    int i, j, k, cont = 0, valido;
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas-qtdX+1; j++) {
            valido = 1;
            for(k = 0; k < qtdX; k++) {
                if(matriz[i][j+k] != 'X') {
                    valido = 0;
                    break;
                }
            }
            if(valido) {
                cont++;
            }
        }
    }
    return cont;
}

int VerificaVertical(int linhas, int colunas, char matriz[linhas][colunas], int qtdX) {
    int i, j, k, cont = 0, valido;
    for(i = 0; i < linhas-qtdX+1; i++) {
        for(j = 0; j < colunas; j++) {
            valido = 1;
            for(k = 0; k < qtdX; k++) {
                if(matriz[i+k][j] != 'X') {
                    valido = 0;
                    break;
                }
            }
            if(valido) {
                cont++;
            }
        }
    }
    return cont;
}


int main() {
    int numX, linhas, colunas;
    char direcao;
    scanf("%d%c", &numX, &direcao);
    scanf("%d %d", &linhas, &colunas);
    scanf("%*[^\n]");
    scanf("%*c");

    char matriz[linhas][colunas];
    LeMatriz(linhas, colunas, matriz);

    switch (direcao) {
        case 'H':
            printf("CONT: %c %d\n", direcao, VerificaHorizontal(linhas, colunas, matriz, numX));
            break;
        
        case 'V':
            printf("CONT: %c %d\n", direcao, VerificaVertical(linhas, colunas, matriz, numX));
            break;
    }

    return 0;
}
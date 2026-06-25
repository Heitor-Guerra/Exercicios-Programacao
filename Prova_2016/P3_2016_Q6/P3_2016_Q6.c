#include <stdio.h>

void LeMatriz(int l, int c, int matriz[l][c]) {
    int i, j;
    for(i = 0; i < l; i++) {
        for(j = 0; j < c; j++) {
            scanf("%1d", &matriz[i][j]);
        }
    }
}

int VerificaBorda(int l, int c, int matriz[l][c], int x, int y) {
    int i, j;
    for(i = x-1; i <= x+1; i++) {
        for(j = y-1; j <= y+1; j++) {
            if(matriz[i][j] == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int l, c, i, j;
    int numBordas = 0;
    scanf("%d %d", &c, &l);
    int arquipelago[l][c];
    LeMatriz(l, c, arquipelago);

    for(i = 1; i < l-1; i++) {
        for(j = 1; j < c-1; j++) {
            if(arquipelago[i][j] == 0 && VerificaBorda(l, c, arquipelago, i, j)) {
                numBordas++;
            }
        }
    }
    printf("%d", numBordas);

    return 0;
}
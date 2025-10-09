#include <stdio.h>

void LeMatriz(int l, int c, int matriz[l][c]) {
    int i, j;
    for(i = 0; i < l; i++) {
        for(j = 0; j < c; j++) {
            scanf("%1d", &matriz[i][j]);
        }
    }
}

int QuantasVezesAContidoB(int l1, int c1, int matriz1[l1][c1], int l2, int c2, int matriz2[l2][c2]) {
    int i, j, k, l;
    int contido = 1, vezes = 0;
    for(i = 0; i < l1-l2+1; i++) {
        for(j = 0; j < c1-c2+1; j++) {
            contido = 1;
            for(k = 0; k < l2; k++) {
                for(l = 0; l < c2; l++) {
                    if(matriz1[i+k][j+l] != matriz2[k][l]) {
                        contido = 0;
                        break;
                    }
                }
                if(!contido) {
                    break;
                }
            }
            if(contido) {
                vezes++;
            }
        }
    }
    return vezes;
}

int main() {
    int l1, c1, l2, c2;
    scanf("%d %d", &l1, &c1);
    int imagem[l1][c1];
    LeMatriz(l1, c1, imagem);
    scanf("%d %d", &l2, &c2);
    int template[l2][c2];
    LeMatriz(l2, c2, template);

    printf("RESP:%d", QuantasVezesAContidoB(l1, c1, imagem, l2, c2, template));

    return 0;
}
#include <stdio.h>

#define TAMANHO_MAXIMO 7

typedef struct {
    int id;
    int tam;
    int matriz[TAMANHO_MAXIMO][TAMANHO_MAXIMO];
} tCartela;

tCartela LeCartela() {
    int i, j;
    tCartela cartela;  
    scanf("%d %d", &cartela.id, &cartela.tam);
    for(j = 0; j < cartela.tam; j++) {
        for(i = 0; i < cartela.tam; i++) {
            scanf("%d", &cartela.matriz[i][j]);
        }
    }
    return cartela;
}

void  ImprimeCartela(tCartela  cartela) {
    int i, j;
    printf("ID:%d\n", cartela.id);
    for(i = 0; i < cartela.tam; i++) {
        for(j = 0; j < cartela.tam; j++) {
            printf("%03d", cartela.matriz[i][j]);
            if(j != cartela.tam - 1) {
                printf("|");
            }
            else{
                printf("\n");
            }
        }
    }
}


int main(){ 
    tCartela cartela; 
    
    cartela = LeCartela(); 
    
    ImprimeCartela(cartela); 

    return 0; 
}
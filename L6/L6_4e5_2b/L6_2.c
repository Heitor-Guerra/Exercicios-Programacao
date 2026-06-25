#include <stdio.h>

#define TAMANHO_MAXIMO 7
#define QUANTIDADE_MAXIMA_CARTELAS 100

typedef struct {
    int id;
    int tam;
    int matriz[TAMANHO_MAXIMO][TAMANHO_MAXIMO];
} tCartela;

typedef struct {
    int numCartelas;
    tCartela cartela[QUANTIDADE_MAXIMA_CARTELAS];
} tPartida;

tCartela LeCartela() {
    int i, j;
    tCartela cartela;  
    scanf("%d %d", &cartela.id, &cartela.tam);
    scanf("%*c");
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

tPartida LeCartelasPartida() {
    int i;
    tPartida partida;
    scanf("%d", &partida.numCartelas);

    for(i = 0; i < partida.numCartelas; i++) {
        partida.cartela[i] = LeCartela();
    }
    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida) {
    int i;
    for(i = partida.numCartelas-1; i >= 0; i--) {
        ImprimeCartela(partida.cartela[i]);
    }
}



int main(){ 
    tPartida partida; 
    
    partida = LeCartelasPartida(); 
    
    ImprimeInvCartelasPartida(partida); 

    return 0; 
}
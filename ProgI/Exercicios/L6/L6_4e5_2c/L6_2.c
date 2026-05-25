#include <stdio.h>

#define TAMANHO_MAXIMO 7
#define QUANTIDADE_MAXIMA_CARTELAS 100

typedef struct {
    int id;
    int tam;
    int matriz[2][TAMANHO_MAXIMO][TAMANHO_MAXIMO];
} tCartela;

typedef struct {
    int numCartelas;
    tCartela cartela[QUANTIDADE_MAXIMA_CARTELAS];
} tPartida;

tCartela LeCartela() {
    int i, j;
    tCartela cartela;  
    scanf("%d %d", &cartela.id, &cartela.tam);
    for(j = 0; j < cartela.tam; j++) {
        for(i = 0; i < cartela.tam; i++) {
            scanf("%d", &cartela.matriz[0][i][j]);
        }
    }
    return cartela;
}

tCartela MarcaCartela(tCartela cartela, int num) {
    int i, j;
    for(i = 0; i < cartela.tam; i++) {
        for(j = 0; j < cartela.tam; j++) {
            if(cartela.matriz[1][i][j] == num) {
                cartela.matriz[1][i][j] = 0;
            }
        }
    }
    return cartela;
}

int VenceuCartela(tCartela cartela) {
    int i, j;
    for(i = 0; i < cartela.tam; i++) {
        for(j = 0; j < cartela.tam; j++) {
            if(cartela.matriz[1][i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

tCartela ResetaCartela(tCartela cartela) {
    int i, j;
    for(j = 0; j < cartela.tam; j++) {
        for(i = 0; i < cartela.tam; i++) {
            cartela.matriz[1][i][j] = cartela.matriz[0][i][j];
        }
    }
    return cartela;
}

void  ImprimeCartela(tCartela  cartela) {
    int i, j;
    printf("ID:%d\n", cartela.id);
    for(i = 0; i < cartela.tam; i++) {
        for(j = 0; j < cartela.tam; j++) {
            printf("%03d", cartela.matriz[0][i][j]);
            if(j != cartela.tam - 1) {
                printf("|");
            }
            else{
                printf("\n");
            }
        }
    }
}



/*-------------------------------------------------------------*/



tPartida LeCartelasPartida() {
    int i;
    tPartida partida;
    scanf("%d", &partida.numCartelas);

    for(i = 0; i < partida.numCartelas; i++) {
        partida.cartela[i] = LeCartela();
    }
    return partida;
}

tPartida ResetaPartida(tPartida partida) {
    int i;
    for(i = 0; i < partida.numCartelas; i++) {
        partida.cartela[i] = ResetaCartela(partida.cartela[i]);
    }
    return partida;
}

void JogaPartida(tPartida partida) {
    int i, j;
    int numSorteado = 0, temVencedor = 0;

    while(scanf("%d", &numSorteado) && numSorteado != -1) {
        for(i = 0; i < partida.numCartelas; i++) {
            partida.cartela[i] = MarcaCartela(partida.cartela[i], numSorteado);
            if(VenceuCartela(partida.cartela[i])) {
                temVencedor = 1;
            }
        }
        if(temVencedor) {
            scanf("%*[^\n]");
            break;
        }
    }

    if(!temVencedor) {
        printf("SEM VENCEDOR\n");
    }
    else {
        printf("COM VENCEDOR\n");
        for(i = 0; i < partida.numCartelas; i++) {
            if(VenceuCartela(partida.cartela[i])) {
                ImprimeCartela(partida.cartela[i]);
            }
        }
    }
}



/*-------------------------------------------------------------*/



int main(){ 
    tPartida partida; 
    int qtdPartidas, i; 
    
    partida = LeCartelasPartida(); 
    
    scanf ("%d", &qtdPartidas); 
    for (i = 0; i < qtdPartidas; i++){ 
        if ( i!=0 ) printf("\n"); 
        printf("PARTIDA %d\n", i+1); 
        partida = ResetaPartida(partida); 
        JogaPartida(partida); 
    } 

    return 0; 
}
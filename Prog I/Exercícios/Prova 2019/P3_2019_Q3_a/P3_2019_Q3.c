#include <stdio.h>

#define MAX_CARROS 100
#define MAX_NOME_CARRO 100

typedef struct {
    int id;
    int qtdPassageiros;
    char tipo[MAX_NOME_CARRO];
    int km;
} tCarro;

typedef struct {
    int numCarros;
    tCarro carros[MAX_CARROS];
} tConcessionaria;

/*------------------------------------------------------------------------------------------------------------*/

tCarro  LeCarro() {
    tCarro carro;

    scanf("%d %d", &carro.id, &carro.qtdPassageiros);
    scanf("%s", carro.tipo);
    scanf("%d", &carro.km);
    return carro;
}

int  ObtemKmCarro(tCarro  carro) {
    return carro.km;
}

int ObtemNumPassageirosCarro(tCarro carro) {
    return carro.qtdPassageiros;
}

void  ImprimeCarro(tCarro  carro) {
    printf("CARRO (%d): %s de %d passageiros e com %d km\n", carro.id, carro.tipo, carro.qtdPassageiros, carro.km);
}

/*------------------------------------------------------------------------------------------------------------*/

tConcessionaria LeCarrosConcessionaria() {
    tConcessionaria concessionaria;
    int i, numCarros;

    scanf("%d", &concessionaria.numCarros);
    for(i = 0; i < concessionaria.numCarros; i++) {
        concessionaria.carros[i] = LeCarro();
    }
    return concessionaria;
}

void  ListaCarrosConcessionaria(tConcessionaria  concessionaria,  int  pass,  int  km) {
    int i;
    for(i = 0; i < concessionaria.numCarros; i++) {
        if(pass > 0) {
            if(pass == ObtemNumPassageirosCarro(concessionaria.carros[i]) && (km >= ObtemKmCarro(concessionaria.carros[i]) || km < 0)) {
                ImprimeCarro(concessionaria.carros[i]);
            }
        }
        else {
            if(km >= ObtemKmCarro(concessionaria.carros[i]) || km < 0) {
                ImprimeCarro(concessionaria.carros[i]);
            }
        }
    }
}

/*------------------------------------------------------------------------------------------------------------*/

int main(){ 
    tConcessionaria concessionaria; 

    concessionaria = LeCarrosConcessionaria(); 
    
    int qtdPassageiros, km, i = 0; 
    while(scanf("%d,%d", &qtdPassageiros, &km) == 2){ 
        printf("Caso %d:\n", ++i); 
        ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km); 
    } 
    
    return 0;  
} 
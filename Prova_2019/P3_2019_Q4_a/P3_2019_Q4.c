#include <stdio.h>

#define MAX_CARROS 100
#define MAX_NOME_CARRO 100

typedef struct {
    int id;
    int qtdPassageiros;
    char tipo[MAX_NOME_CARRO];
    int km;
    int alugado;
} tCarro;

typedef struct {
    int numCarros;
    tCarro carros[MAX_CARROS];
} tConcessionaria;

/*--------------------------------------------------Carro--------------------------------------------------*/

tCarro  LeCarro() {
    tCarro carro;

    scanf("%d %d", &carro.id, &carro.qtdPassageiros);
    scanf("%s", carro.tipo);
    scanf("%d", &carro.km);
    carro.alugado = 0;
    return carro;
}

tCarro AlugaCarro(tCarro carro, int cliente) {
    carro.alugado = cliente;
    return carro;
}

tCarro DevolveCarro(tCarro carro) {
    carro.alugado = 0;
    return carro;
}

int EstaDisponivelCarro(tCarro carro) {
    return !carro.alugado;
}

int  ObtemKmCarro(tCarro  carro) {
    return carro.km;
}

int ObtemNumPassageirosCarro(tCarro carro) {
    return carro.qtdPassageiros;
}

int ObtemClienteAlugouCarro(tCarro carro) {
    return carro.alugado;
}

void  ImprimeCarro(tCarro  carro) {
    printf("CARRO (%d): %s de %d passageiros e com %d km\n", carro.id, carro.tipo, carro.qtdPassageiros, carro.km);
}

/*-----------------------------------------------Concessionaria-----------------------------------------------*/

tConcessionaria LeCarrosConcessionaria() {
    tConcessionaria concessionaria;
    int i, numCarros;

    scanf("%d", &concessionaria.numCarros);
    for(i = 0; i < concessionaria.numCarros; i++) {
        concessionaria.carros[i] = LeCarro();
    }
    return concessionaria;
}

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km) {
    int i;
    for(i = 0; i < concessionaria.numCarros; i++) {
        if((pass == ObtemNumPassageirosCarro(concessionaria.carros[i]) || pass < 0) && (km >= ObtemKmCarro(concessionaria.carros[i]) || km < 0) && EstaDisponivelCarro(concessionaria.carros[i])) {
            printf("Alugado (cliente %d) -> ", cliente);
            ImprimeCarro(concessionaria.carros[i]);
            concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], cliente);
            return concessionaria;
        }
    }
    printf("Carro Indisponivel\n");
    return concessionaria;
}

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente) {
    int i;
    for(i = 0; i < concessionaria.numCarros; i++) {
        if(ObtemClienteAlugouCarro(concessionaria.carros[i]) == cliente) {
            printf("Devolvido (cliente %d) -> ", cliente);
            ImprimeCarro(concessionaria.carros[i]);
            concessionaria.carros[i] = DevolveCarro(concessionaria.carros[i]);
            return concessionaria;
        }
    }
    return concessionaria;
}

/*------------------------------------------------------------------------------------------------------------*/

int main(){ 
    int cliente;
    char evento;
    int qtdPassageiros, km; 
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria(); 
    
    while(scanf("%d,%c", &cliente, &evento) == 2) {
        if(evento == 'A') {
            scanf("%d,%d", &qtdPassageiros, &km);
            concessionaria = AlugaCarroConcessionaria(concessionaria, cliente, qtdPassageiros, km);
        } 
        else if(evento == 'D') {
            concessionaria = DevolveCarroConcessionaria(concessionaria, cliente);
        }
    } 
    
    return 0;  
} 
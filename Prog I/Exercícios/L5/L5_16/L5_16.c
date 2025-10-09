#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
 
typedef struct{ 
    int codigo; 
    char sobrenome[21]; 
    char nome[21]; 
    int nota; 
    int idade; 
} tCandidato; 
 
tCandidato LeCandidato(){ 
    tCandidato candidato; 
    scanf("%*[^{]"); 
    scanf("%*[{ ]"); 
    scanf("%d", &candidato.codigo); 
    scanf("%*[, ]"); 
    scanf("%[^,],", candidato.sobrenome); 
    scanf("%*[ ]"); 
    scanf("%[^,],", candidato.nome); 
    scanf("%d", &candidato.nota); 
    scanf("%*[, ]"); 
    scanf("%d", &candidato.idade); 
    scanf("%*[^\n]\n"); 
    return candidato; 
}

void ImprimeCandidato(tCandidato candidato) {
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}

void TrocaPosVetor(tCandidato vet[], int pos1, int pos2) {
    tCandidato aux;
    aux = vet[pos1];
    vet[pos1] = vet[pos2];
    vet[pos2] = aux;
}

void OrdenaCrescente(tCandidato vet[], int qtd) {
    int i, pronto = 0;
    tCandidato aux;

    while(!pronto) {
        for(i = 1; i < qtd; i++) {
            if(vet[i-1].nota < vet[i].nota) {
                TrocaPosVetor(vet, i-1, i);
            }
            else if(vet[i-1].nota == vet[i].nota) {
                if(vet[i-1].idade > vet[i].idade) {
                    TrocaPosVetor(vet, i-1, i);
                }
                else if(vet[i-1].idade == vet[i].idade && vet[i-1].codigo > vet[i].codigo) {
                    TrocaPosVetor(vet, i-1, i);
                }
            }
        }
        pronto = 1;
        for(i = 1; i < qtd; i++) {
            if(vet[i-1].nota < vet[i].nota) {
                pronto = 0;
            }
            else if(vet[i-1].nota == vet[i].nota) {
                if(vet[i-1].idade > vet[i].idade) {
                    pronto = 0;
                }
                else if(vet[i-1].idade == vet[i].idade && vet[i-1].codigo > vet[i].codigo) {
                    pronto = 0;
                }
            }
        }
    }
}


int main(){ 
    int qtdCand, i, j;

    char nomeCompleto[42];

    scanf("%d", &qtdCand); 
    tCandidato candidatos[qtdCand]; 
  
    for(i = 0; i < qtdCand; i++) { 
        candidatos[i] = LeCandidato();
    }

    OrdenaCrescente(candidatos, qtdCand);

    for(i = 0; i < qtdCand; i++) {
        ImprimeCandidato(candidatos[i]);
    }
  
    return 0;     
} 
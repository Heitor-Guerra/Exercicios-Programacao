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

void ConcatenaString(char * str1, char * str2, char * strOut) {
    char c = 0;
    int i = 0, pos = 0;
    for(i = 0; str1[i] != '\0'; i++) {
        strOut[i] = str1[i];
    }
    pos = i;
    for(i = 0; str2[i] != '\0'; i++) {
        strOut[pos+i] = str2[i];
    }
    strOut[pos+i] = '\0';
}



void OrdenaCrescente(tCandidato * vet, int qtd) {
    int i, j;
    tCandidato aux;
    char nomeCompletoA[42], nomeCompletoB[42];

    for(i = 0; i < qtd; i++) {
        for(j = 0; j < qtd; j++) {
            ConcatenaString(vet[i].nome, vet[i].sobrenome, nomeCompletoA);
            ConcatenaString(vet[j].nome, vet[j].sobrenome, nomeCompletoB);
            if(strcmp(nomeCompletoA, nomeCompletoB) < 0) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
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
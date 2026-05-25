#include <stdio.h> 
#include <stdlib.h> 
 
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
 
int ComparaString(char * str1, char * str2) {
    int i;
    for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if(str1[i] != str2[i]) {
            return 0;
        } 
    }
    if(str1[i] == str2[i]) {
        return 1;
    }
    return 0;
}
 
int main(){ 
    int qtdCand, i, j;
  
    scanf("%d", &qtdCand); 
    int posicoesVerificadas[qtdCand]; 
    for(i = 0; i < qtdCand; i++) {
        posicoesVerificadas[i] = 0;
    }
    tCandidato candidatos[qtdCand]; 
  
    for(i = 0; i < qtdCand; i++) { 
        candidatos[i] = LeCandidato();
    }


    for(i = 0; i < qtdCand; i++) {
        if(posicoesVerificadas[i] == 1) {
            continue;
        }
        for(j = i + 1; j < qtdCand; j++) {
            if(ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome)) {
                if(posicoesVerificadas[i] == 0) {
                    ImprimeCandidato(candidatos[i]);
                }
                ImprimeCandidato(candidatos[j]);
                posicoesVerificadas[j] = 1;
                posicoesVerificadas[i] = 1;
            }
        }
    }

  
    return 0;     
} 
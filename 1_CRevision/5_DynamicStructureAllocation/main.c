#include "filme.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int numFilmes = 0;

    float mediaNotas = 0;
    scanf("%d\n", &numFilmes);

    Filme **filmes = (Filme**)malloc(numFilmes*sizeof(Filme*));

    for(int i = 0; i < numFilmes; i++) {
        filmes[i] = leFilme();
        calculaMediaNotasFilme(filmes[i]);

        mediaNotas += getMediaFilme(filmes[i]);
    }
    mediaNotas /= (float)numFilmes;

    for(int i = 0; i < numFilmes; i++) {
        if(getMediaFilme(filmes[i]) > mediaNotas) {
            imprimeNomeFilme(filmes[i]);
        }
    }

    for(int i = 0; i < numFilmes; i++) {
        desalocaFilme(filmes[i]);
    }
    free(filmes);

}
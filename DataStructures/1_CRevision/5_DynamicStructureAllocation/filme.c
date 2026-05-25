#include "filme.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Filme {
    char nome[32];
    float *notas;
    int numNotas;

    float mediaNotas;
};

Filme *inicializaFilme(char *nome, int numNotas, float *notas) {
    Filme *filme = (Filme*)malloc(sizeof(Filme));
    
    strcpy(filme->nome, nome);
    filme->numNotas = numNotas;
    filme->notas = notas;
    filme->mediaNotas = 0;

    return filme;
}

Filme *leFilme() {
    char nome[33];
    float *notas;
    int numNotas;

    scanf("%[^\n]\n", nome);
    scanf("%d\n", &numNotas);
    notas = (float*)malloc(numNotas*sizeof(float));

    for(int i = 0; i < numNotas; i++) {
        scanf("%f\n", notas+i);
    }

    return inicializaFilme(nome, numNotas, notas);
}

void calculaMediaNotasFilme(Filme* filme) {
    float media = 0;
    for(int i = 0; i < filme->numNotas; i++) {
        media += filme->notas[i];
    }
    media /= filme->numNotas;
    filme->mediaNotas = media;
}

float getMediaFilme(Filme* filme) {
    return filme->mediaNotas;
}

void imprimeNomeFilme(Filme *filme) {
    printf("%s\n", filme->nome);
}

void desalocaFilme(Filme* filme) {
    free(filme->notas);
    free(filme);
}
#include "atendimento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Atendimento{
    char nome[32];
    char cpf[12];
};

Atendimento* criaAtendimento(char *nome, char*cpf) {
    Atendimento* a = (Atendimento*)malloc(sizeof(Atendimento));
    strcpy(a->nome, nome);
    strcpy(a->nome, nome);
    return a;
}

Atendimento* leAtendimento() {
    char nome[32];
    char cpf[12];
    scanf("%s %s", nome, cpf);

    return criaAtendimento(nome, cpf);
}

void printNomeAtendimento(Atendimento* a) {
    printf("%s\n", a->nome);
}

void destroiAtendimento(Atendimento* a) {
    free(a);
}
#include "notasAluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NotasAluno{
    char nome[32];
    float nota_t1, nota_t2, nota_prova;
    float percentual_falta;
};

NotasAluno* inicializaAluno(char nome[32], float nota_t1, float nota_t2, float nota_prova, float percentual_falta) {
    NotasAluno* aluno = (NotasAluno*)malloc(sizeof(NotasAluno));
    strcpy(aluno->nome, nome);
    aluno->nota_prova = nota_prova;
    aluno->nota_t1 = nota_t1;
    aluno->nota_t2 = nota_t2;
    aluno->percentual_falta = percentual_falta;

    return aluno;
}

NotasAluno* leAluno() {
    char nome[32];
    float nota_t1, nota_t2, nota_prova;
    float percentual_falta;
    scanf("%[^\n]\n",nome);
    scanf("%f\n", &nota_t1);
    scanf("%f\n", &nota_t2);
    scanf("%f\n", &nota_prova);
    scanf("%f\n", &percentual_falta);

    return inicializaAluno(nome, nota_t1, nota_t2, nota_prova, percentual_falta);
}

int estaAprovadoAluno(NotasAluno* aluno) {
    return notaMediaAluno(aluno) >= 7 && aluno->percentual_falta <= 0.25;
}

float notaMediaAluno(NotasAluno* aluno) {
    return (aluno->nota_prova*0.5+aluno->nota_t1*0.25+aluno->nota_t2*0.25);
}

void destroiAluno(NotasAluno* aluno) {
    free(aluno);
}
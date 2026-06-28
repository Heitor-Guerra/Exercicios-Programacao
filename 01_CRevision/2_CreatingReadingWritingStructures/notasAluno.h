#ifndef _NOTAS_ALUNO_H
#define _NOTAS_ALUNO_H

typedef struct NotasAluno NotasAluno;

NotasAluno* inicializaALuno(char nome[32], float nota_t1, float nota_t2, float nota_prova, float percentual_falta);

NotasAluno* leAluno();

int estaAprovadoAluno(NotasAluno* aluno);

float notaMediaAluno(NotasAluno* aluno);

void destroiAluno(NotasAluno* aluno);

#endif
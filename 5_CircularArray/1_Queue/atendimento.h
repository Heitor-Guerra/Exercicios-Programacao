#ifndef _ATENDIMENTO_H
#define _ATENDIMENTO_H

typedef struct Atendimento Atendimento;

Atendimento* criaAtendimento(char *nome, char*cpf);

Atendimento* leAtendimento();

void printNomeAtendimento(Atendimento* a);

void destroiAtendimento(Atendimento* a);

#endif



#ifndef _FILME_H_
#define _FILME_H_

typedef struct Filme Filme;


Filme *leFilme();
Filme *inicializaFilme(char *nome, int numNotas, float *notas);
void calculaMediaNotasFilme(Filme* filme);
float getMediaFilme(Filme* filme);
void imprimeNomeFilme(Filme *filme);
void desalocaFilme(Filme* filme);


#endif
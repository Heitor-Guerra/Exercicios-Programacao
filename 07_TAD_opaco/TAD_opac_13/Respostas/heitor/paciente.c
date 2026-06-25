#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL_LESOES_PAC 2
#define TAM_INCREMENTO_LESOES_PAC 2
struct Paciente {
  char nome[MAX_NOME_PAC];
  char cartao[MAX_CARTAO_SUS];
  char genero;
  Data *nasc;

  int numLesoesUsado;
  int numLesoesAloc;
  Lesao **lesoes;
};

/*
Função que cria um paciente a partir dos parâmetros fornecidos.
@param nome: Nome do paciente.
@param cartaoSus: Cartão SUS do paciente.
@param genero: Gênero do paciente.
@param dataNasc: Data de nascimento do paciente.
@return Ponteiro para o paciente criado.
*/
Paciente *criaPaciente(char *nome, char *cartaoSus, char genero,
                       Data *dataNasc) {
  Paciente *p = (Paciente *)malloc(sizeof(Paciente));
  p->lesoes = (Lesao **)malloc(TAM_INICIAL_LESOES_PAC * sizeof(Lesao *));
  p->numLesoesAloc = TAM_INICIAL_LESOES_PAC;
  p->numLesoesUsado = 0;

  strcpy(p->nome, nome);
  strcpy(p->cartao, cartaoSus);
  p->genero = genero;
  p->nasc = dataNasc;

  return p;
}

/*
Função que lê os dados de um paciente a partir da entrada padrão. Consulte o
enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para o paciente lido.
*/
Paciente *lerPaciente() {
  char nome[MAX_NOME_PAC], cartao[MAX_CARTAO_SUS];
  char genero;
  Data *data;

  scanf("%[^\n]\n", nome);
  data = lerData();
  scanf("%[^\n]\n", cartao);
  scanf("%c\n", &genero);

  Paciente *p = criaPaciente(nome, cartao, genero, data);
  return p;
}

/*
Função que adiciona uma lesão ao paciente.
Basicamente, a lesão é adicionada à lista de lesões do paciente realizando toda
a alocação dinâmica necessária.
@param p: Ponteiro para o paciente ao qual a lesão será vinculada.
@param l: Ponteiro para a lesão a ser vinculada ao paciente.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l) {
  if (p->numLesoesUsado >= p->numLesoesAloc) {
    p->numLesoesAloc += TAM_INCREMENTO_LESOES_PAC;
    p->lesoes = (Lesao **)malloc(p->numLesoesAloc * sizeof(Lesao *));
  }
  p->lesoes[p->numLesoesUsado] = l;
  p->numLesoesUsado++;
}

/*
Função que calcula a idade do paciente em anos completos com base em uma data de
referência.
@param p: O paciente cuja idade será calculada.
@param dataBase: A data de referência para o cálculo da idade.
@return A idade do paciente em anos completos.
*/
int calculaIdadePaciente(Paciente *p, Data *dataBase) {
  return diferencaAnoData(p->nasc, dataBase);
}

/*
Função que obtém o cartão SUS de um paciente.
@param p: Ponteiro para o paciente do qual se deseja obter o cartão SUS.
@return Ponteiro para cartão SUS do paciente.
*/
char *getCartaoSusPaciente(Paciente *p) { return p->cartao; }

/*
Função que obtém o número de lesões associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões será obtida.
@return O número de lesões do paciente.
*/
int getNumLesoesPaciente(Paciente *p) { return p->numLesoesUsado; }

/*
Função que calcula a quantidade de lesões cirúrgicas (malignas) associadas a um
paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões cirúrgicas será
calculada.
@return A quantidade de lesões cirúrgicas do paciente.
*/
int qtdLesoesCirurgicasPaciente(Paciente *p) {
  int numCir = 0;
  for (int i = 0; i < p->numLesoesUsado; i++) {
    numCir += verificaCirurgicaLesao(p->lesoes[i]);
  }
  return numCir;
}

/*
Função que imprime o nome do paciente e o ID das lesões associadas a ele
(exatamente como solicitado no enunciado e nos casos de teste).
@param p: Ponteiro para o paciente cujas informações serão impressas.
*/
void imprimePaciente(Paciente *p) {
  if (p->numLesoesUsado <= 0) {
    return;
  }
  printf("- %s - ", p->nome);
  for (int i = 0; i < p->numLesoesUsado; i++) {
    imprimeIdLesao(p->lesoes[i]);
  }
  printf("\n");
}

/*
Função que libera a memória alocada para um paciente.
@param p: Ponteiro para o paciente a ser liberado.
*/
void liberaPaciente(Paciente *p) {
  for (int i = 0; i < p->numLesoesUsado; i++) {
    liberaLesao(p->lesoes[i]);
  }
  liberaData(p->nasc);
  free(p->lesoes);
  free(p);
}

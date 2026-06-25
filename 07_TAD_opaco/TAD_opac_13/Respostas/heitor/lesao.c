#include "lesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lesao {
  char cartao[MAX_CARTAO_LES];
  char id[MAX_ID_LES];
  char diag[MAX_DIAG_LES];
  char regiao[MAX_REG_LES];
  int malig;
};

/*
Função que cria uma lesão a partir dos parâmetros fornecidos.
@param cartaoSus: Cartão SUS do paciente associado à lesão.
@param id: Identificador único da lesão.
@param diagnostico: Diagnóstico da lesão.
@param regiao: Região do corpo onde a lesão está localizada.
@param malignidade: Indicador de malignidade (1 para maligna, 0 para benigna).
@return Ponteiro para a lesão criada.
*/
Lesao *criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao,
                 int malignidade) {
  Lesao *l = (Lesao *)malloc(sizeof(Lesao));
  l->malig = malignidade;
  strcpy(l->cartao, cartaoSus);
  strcpy(l->id, id);
  strcpy(l->diag, diagnostico);
  strcpy(l->regiao, regiao);

  return l;
}

/*
Função que lê os dados de uma lesão a partir da entrada padrão. Consulte o
enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para a lesão lida.
*/
Lesao *lerLesao() {
  char cartao[MAX_CARTAO_LES];
  char id[MAX_ID_LES];
  char diag[MAX_DIAG_LES];
  char reg[MAX_REG_LES];
  int malig;

  scanf("%[^\n]\n", cartao);
  scanf("%[^\n]\n", id);
  scanf("%[^\n]\n", diag);
  scanf("%[^\n]\n", reg);
  scanf("%d\n", &malig);

  Lesao *l = criaLesao(cartao, id, diag, reg, malig);

  return l;
}

/*
Função que obtém o cartão SUS associado a uma lesão.
@param l: Ponteiro para a lesão da qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
char *getCartaoSusLesao(Lesao *l) { return l->cartao; }

/*
Função que verifica se uma lesão é cirúrgica (maligna).
@param l: Ponteiro para a lesão a ser verificada.
@return 1 se a lesão for cirúrgica (maligna), 0 caso contrário.
*/
int verificaCirurgicaLesao(Lesao *l) { return l->malig > 50; }

/*
Função que imprime o identificador de uma lesão.
@param l: Ponteiro para a lesão cuja identificação será impressa.
*/
void imprimeIdLesao(Lesao *l) { printf("%s ", l->id); }

/*
Função que libera a memória alocada para uma lesão.
@param l: Ponteiro para a lesão a ser liberada.
*/
void liberaLesao(Lesao *l) { free(l); }

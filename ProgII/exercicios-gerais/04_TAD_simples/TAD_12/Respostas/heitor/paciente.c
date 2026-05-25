#include "paciente.h"
#include <stdio.h>
#include <string.h>
/*
Função que cria um paciente a partir dos parâmetros fornecidos.
@param nome: Nome do paciente.
@param cartaoSus: Cartão SUS do paciente.
@param genero: Gênero do paciente.
@param dataNasc: Data de nascimento do paciente.
@return O paciente criado.
*/
Paciente criaPaciente(char *nome, char *cartaoSus, char genero, Data dataNasc) {
  Paciente pac;
  strcpy(pac.nome, nome);
  strcpy(pac.cartaoSus, cartaoSus);
  pac.genero = genero;
  pac.dataNasc = dataNasc;
  pac.numLesoes = 0;
  return pac;
}

/*
Função que lê os dados de um paciente a partir da entrada padrão. Consulte o
enunciado e/ou os casos de teste para o formato esperado.
@return O paciente lido.
*/
Paciente lerPaciente() {
  char nome[MAX_NOME_PAC], cartaoSus[MAX_CARTAO_SUS], genero;
  Data dataNasc;

  scanf("%[^\n]\n", nome);
  dataNasc = lerData();
  scanf("%[^\n]\n", cartaoSus);
  scanf("%c\n", &genero);

  Paciente pac = criaPaciente(nome, cartaoSus, genero, dataNasc);
  return pac;
}

/*
Função que vincula uma lesão a um paciente.
Basicamente, a lesão é adicionada à lista de lesões do paciente se houver espaço
disponível. O vínculo é realizado de acordo com o cartão do SUS.
@param p: O paciente ao qual a lesão será vinculada.
@param l: A lesão a ser vinculada ao paciente.
@return O paciente atualizado com a lesão vinculada.
*/
Paciente vinculaLesaoPaciente(Paciente p, Lesao l) {
  if (p.numLesoes >= MAX_LESOES) {
    printf("Lesoes maximas alcancadas no paciente: %s\n", p.nome);
    return p;
  }
  p.lesoes[p.numLesoes] = l;
  p.numLesoes++;
  return p;
}

/*
Função que calcula a idade do paciente em anos completos com base em uma data de
referência.
@param p: O paciente cuja idade será calculada.
@param dataBase: A data de referência para o cálculo da idade.
@return A idade do paciente em anos completos.
*/
int calculaIdadePaciente(Paciente p, Data dataBase) {
  return diferencaAnoData(p.dataNasc, dataBase);
}

/*
Função que obtém o cartão SUS de um paciente.
@param p: O paciente do qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
void getCartaoSusPaciente(Paciente p, char *cartaoSus) {
  strcpy(cartaoSus, p.cartaoSus);
}

/*
Função que obtém o número de lesões associadas a um paciente.
@param p: O paciente cuja quantidade de lesões será obtida.
@return O número de lesões do paciente.
*/
int getNumLesoesPaciente(Paciente p) { return p.numLesoes; }

/*
Função que calcula a quantidade de lesões cirúrgicas (malignas) associadas a um
paciente.
@param p: O paciente cuja quantidade de lesões cirúrgicas será calculada.
@return A quantidade de lesões cirúrgicas do paciente.
*/
int qtdLesoesCirurgicasPaciente(Paciente p) {
  int cirurgias = 0;
  for (int i = 0; i < p.numLesoes; i++) {
    cirurgias += verificaCirurgicaLesao(p.lesoes[i]);
  }
  return cirurgias;
}

/*
Função que imprime o nome do paciente e o ID das lesões associadas a ele
(exatamente como solicitado no enunciado e nos casos de teste).
@param p: O paciente cujas informações serão impressas.
*/
void imprimePaciente(Paciente p) {
  if (p.numLesoes <= 0) {
    return;
  }
  printf("- %s - ", p.nome);
  for (int i = 0; i < p.numLesoes; i++) {
    imprimeIdLesao(p.lesoes[i]);
  }
  puts("");
}

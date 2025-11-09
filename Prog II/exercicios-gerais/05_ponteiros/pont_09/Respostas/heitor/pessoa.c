#include "pessoa.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0')
 * e inicializa os ponteiros para pai e mae com NULL.
 *
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa() {
  tPessoa pessoa;
  pessoa.nome[0] = '\0';
  pessoa.pai = NULL;
  pessoa.mae = NULL;
  return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 *
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa) { scanf("\n%[^\n]", pessoa->nome); }

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 *
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 *
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
  return pessoa->mae != NULL || pessoa->pai != NULL;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai
 * e/ou mae associado(s). Alem disso, imprimir o nome do irmao caso exista.
 *
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa) {
  if (VerificaSeTemPaisPessoa(pessoa)) {
    printf("NOME COMPLETO: %s\n", pessoa->nome);
    printf("PAI: ");
    if (pessoa->pai != NULL) {
      printf("%s\n", pessoa->pai->nome);
    } else {
      printf("NAO INFORMADO\n");
    }
    printf("MAE: ");
    if (pessoa->mae != NULL) {
      printf("%s\n", pessoa->mae->nome);
    } else {
      printf("NAO INFORMADO\n");
    }
    printf("\n");
  }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a
 * representar as associacoes lidas
 *
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
  int numAssociacoes;
  scanf("\n%d", &numAssociacoes);
  for (int i = 0; i < numAssociacoes; i++) {
    int indiceM, indiceP, indiceF;
    scanf("\nmae: %d, pai: %d, filho: %d", &indiceM, &indiceP, &indiceF);

    if (indiceM != -1) {
      pessoas[indiceF].mae = (pessoas + indiceM);
    }
    if (indiceP != -1) {
      pessoas[indiceF].pai = (pessoas + indiceP);
    }
  }
}

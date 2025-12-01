#include "loja.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_INICIAL_VENDEDORES 1
#define TAM_INCREMENTO_VENDEDORES 1

/**
 * @brief Abre uma nova loja.
 *
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja *AbreLoja(int id, float aluguel) {
  tLoja *loja = (tLoja *)malloc(sizeof(tLoja));
  loja->vendedores =
      (tVendedor **)malloc(TAM_INICIAL_VENDEDORES * sizeof(tVendedor *));
  loja->maxVendedores = TAM_INICIAL_VENDEDORES;
  loja->totalVendedores = 0;
  loja->id = id;
  loja->aluguel = aluguel;
  loja->lucro = 0;

  return loja;
}

/**
 * @brief Libera a memória alocada para uma loja.
 *
 * @param loja Ponteiro para uma loja a ser apagado.
 */
void ApagaLoja(tLoja *loja) {
  for (int i = 0; i < loja->totalVendedores; i++) {
    ApagaVendedor(loja->vendedores[i]);
  }
  free(loja->vendedores);
  free(loja);
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser
 * verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro,
 * ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja *loja, int id) { return loja->id == id; }

/**
 * @brief Contrata um novo vendedor para a loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a
 * ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo
 * vendedor contratado.
 */
void ContrataVendedor(tLoja *loja, tVendedor *vendedor) {
  if (loja->totalVendedores >= loja->maxVendedores) {
    loja->maxVendedores += TAM_INCREMENTO_VENDEDORES;
    loja->vendedores = (tVendedor **)realloc(
        loja->vendedores, loja->maxVendedores * sizeof(tVendedor *));
  }
  loja->vendedores[loja->totalVendedores] = vendedor;
  loja->totalVendedores++;
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda
 * registrada.
 */
void RegistraVenda(tLoja *loja, char *nome, float valor) {
  for (int i = 0; i < loja->totalVendedores; i++) {
    if (VerificaNomeVendedor(loja->vendedores[i], nome)) {
      ContabilizaVenda(loja->vendedores[i], valor);
      return;
    }
  }
}

/**
 * @brief Calcula o lucro da loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro
 * calculado.
 */
void CalculaLucro(tLoja *loja) {
  loja->lucro -= loja->aluguel;
  for (int i = 0; i < loja->totalVendedores; i++) {
    loja->lucro += GetTotalVendido(loja->vendedores[i]) -
                   GetTotalRecebido(loja->vendedores[i]);
  }
}

/**
 * @brief Imprime o relatório da loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja *loja) {
  printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);
  for (int i = 0; i < loja->totalVendedores; i++) {
    ImprimeRelatorioVendedor(loja->vendedores[i]);
  }
}

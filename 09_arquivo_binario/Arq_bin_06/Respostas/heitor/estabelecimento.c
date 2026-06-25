#include "estabelecimento.h"
#include "vector.h"
#include <stdlib.h>

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento {
  Vector *produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na
 * alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento() {
  tEstabelecimento *est = (tEstabelecimento *)malloc(sizeof(tEstabelecimento));
  est->produtos = VectorConstruct();

  return est;
}

void DestroiProdutoEst(void *dado) {
  tProduto *pro = (tProduto *)dado;
  DestroiProduto(pro);
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento) {
  VectorDestroy(estabelecimento->produtos, DestroiProdutoEst);
  free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento,
                                    tProduto *produto) {
  VectorPushBack(estabelecimento->produtos, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a
 * quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento) {
  char caminho[50];
  scanf("%s", caminho);
  FILE *file = fopen(caminho, "rb");

  int numPro;
  fread(&numPro, sizeof(int), 1, file);
  for (int i = 0; i < numPro; i++) {
    tProduto *temp = LeProduto(file);
    AdicionaProdutoEstabelecimento(estabelecimento, temp);
  }

  fclose(file);
}

/**
 * @brief Função para obter o valor total de produtos vendidos em um
 * estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
 */
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento) {
  float total = 0;
  for (int i = 0; i < VectorSize(estabelecimento->produtos); i++) {
    tProduto *temp = (tProduto *)VectorGet(estabelecimento->produtos, i);
    total += GetQuantidadeVendidaProduto(temp) * GetPrecoProduto(temp);
  }
  return total;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento,
 * cotendo o valor total vendido e a porcentagem de cada produto relativo ao
 * total vendido. Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento) {
  float total = GetValorTotalVendidoEstabelecimento(estabelecimento);
  printf("Valor total vendido: R$ %.2f\n", total);
  printf("Produtos vendidos:\n");
  printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
  for (int i = 0; i < VectorSize(estabelecimento->produtos); i++) {
    tProduto *temp = (tProduto *)VectorGet(estabelecimento->produtos, i);
    float prc =
        GetPrecoProduto(temp) * GetQuantidadeVendidaProduto(temp) * 100 / total;
    ImprimeProduto(temp);
    printf(";%.2f%%\n", prc);
  }
}

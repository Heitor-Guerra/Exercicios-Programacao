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
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento
 * no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento) {
  printf("Produtos em falta: \n");
  printf("Codigo;Nome;Preco\n");
  int numFalta = 0;
  for (int i = 0; i < VectorSize(estabelecimento->produtos); i++) {
    if (!TemEstoqueProduto(
            (tProduto *)VectorGet(estabelecimento->produtos, i))) {
      numFalta++;
      ImprimeProduto((tProduto *)VectorGet(estabelecimento->produtos, i));
    }
  }
  if (numFalta == 0) {
    printf("Nao ha produtos em falta!\n");
  }
}

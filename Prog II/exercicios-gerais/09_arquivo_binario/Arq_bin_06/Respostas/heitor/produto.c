#include "produto.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar um produto.
 */
struct Produto {
  char nome[50];
  float preco;
  int qtd;
  int id;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação
 * de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco,
                      int quantidadeVendida) {
  tProduto *p = (tProduto *)malloc(sizeof(tProduto));
  p->id = codigo;
  p->preco = preco;
  p->qtd = quantidadeVendida;
  strcpy(p->nome, nome);

  return p;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto) { free(produto); }

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo:
 * Código (int)
 * Nome (string)
 * Preço (float)
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo) {
  char nome[50];
  float preco;
  int qtd;
  int id;

  fread(&id, sizeof(int), 1, arquivo);
  fread(nome, sizeof(char), 50, arquivo);
  fread(&preco, sizeof(float), 1, arquivo);
  fread(&qtd, sizeof(int), 1, arquivo);

  return CriaProduto(id, nome, preco, qtd);
}

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto) { return produto->qtd > 0; }

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto) {
  printf("%d;%s;R$ %.2f;%d", produto->id, produto->nome, produto->preco,
         produto->qtd);
}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto) { return produto->qtd; }
/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
 */
float GetPrecoProduto(tProduto *produto) { return produto->preco; }

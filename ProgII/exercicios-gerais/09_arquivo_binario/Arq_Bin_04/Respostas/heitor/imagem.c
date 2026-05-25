#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem {
  void *matriz;
  int linhas, colunas;
  Tipo type;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na
 * memória.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou
 * alocação de memória), a função imprime uma mensagem de erro e termina o
 * programa.
 */
Imagem *LerImagem(const char *caminho) {
  Imagem *img = (Imagem *)malloc(sizeof(Imagem));
  FILE *file = fopen(caminho, "rb");

  fread(&img->linhas, sizeof(int), 1, file);
  fread(&img->colunas, sizeof(int), 1, file);
  fread(&img->type, sizeof(Tipo), 1, file);

  switch (img->type) {
  case FLOAT:
    img->matriz = malloc(img->linhas * img->colunas * sizeof(int));
    fread(img->matriz, sizeof(int), img->linhas * img->colunas, file);
    break;
  case INT:
    img->matriz = malloc(img->linhas * img->colunas * sizeof(float));
    fread(img->matriz, sizeof(float), img->linhas * img->colunas, file);
    break;
  }

  fclose(file);
  return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img) {
  free(img->matriz);
  free(img);
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img) { return img->linhas; }

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img) { return img->colunas; }

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img) { return img->type; }

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img) { return img->matriz; }

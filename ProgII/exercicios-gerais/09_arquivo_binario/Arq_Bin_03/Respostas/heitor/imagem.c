#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem {
  void *matriz;
  int linhas, colunas;
  int numBytesLidos;
  Tipo type;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na
 * memória. A função também armazena o número de bytes lidos na estrutura
 * Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou
 * alocação de memória), a função imprime uma mensagem de erro e termina o
 * programa.
 */
Imagem *LerImagem(const char *caminho) {
  Imagem *img = (Imagem *)malloc(sizeof(Imagem));
  FILE *file = fopen(caminho, "rb");

  img->numBytesLidos = 0;

  img->numBytesLidos += fread(&img->linhas, sizeof(int), 1, file);
  img->numBytesLidos += fread(&img->colunas, sizeof(int), 1, file);
  img->numBytesLidos += fread(&img->type, sizeof(Tipo), 1, file);

  switch (img->type) {
  case FLOAT:
    img->matriz = malloc(img->linhas * img->colunas * sizeof(int));
    img->numBytesLidos +=
        fread(img->matriz, sizeof(int), img->linhas * img->colunas, file);
    break;
  case INT:
    img->matriz = malloc(img->linhas * img->colunas * sizeof(float));
    img->numBytesLidos +=
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
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img) { return img->numBytesLidos; }

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img) {
  switch (img->type) {
  case FLOAT:
    for (int i = 0; i < img->linhas; i++) {
      for (int j = 0; j < img->colunas; j++) {
        printf("%.2f ", *((float *)img->matriz + img->colunas * i + j));
      }
      printf("\n");
    }
    break;
  case INT:
    for (int i = 0; i < img->linhas; i++) {
      for (int j = 0; j < img->colunas; j++) {
        printf("%d ", *((int *)img->matriz + img->colunas * i + j));
      }
      printf("\n");
    }
    break;
  }
}

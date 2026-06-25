#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem {
  Tipo type;
  int altura;
  int largura;
  void *dados;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img) { return img->altura; }

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img) { return img->largura; }

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img) { return img->type; }

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma
 * linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img) { return img->dados; }

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem,
 * o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo) {
  Imagem *img = (Imagem *)malloc(sizeof(Imagem));
  img->altura = altura;
  img->largura = largura;
  img->type = tipo;

  int size = 0;
  switch (tipo) {
  case INT:
    size = sizeof(int);
    break;
  case FLOAT:
    size = sizeof(float);
    break;
  }
  img->dados = (void *)malloc(altura * largura * size);

  return img;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de
 * dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da
 * imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função
 * CriarImagem).
 */
Imagem *LerImagem() {
  int altura, largura;
  int tipo;
  scanf("%d %d %d", &altura, &largura, &tipo);
  Imagem *img = CriarImagem(altura, largura, tipo);

  if (tipo == INT) {
    for (int i = 0; i < altura * largura; i++) {
      scanf("%d", (int *)img->dados + i);
    }
  } else if (tipo == FLOAT) {
    for (int i = 0; i < altura * largura; i++) {
      scanf("%f", (float *)img->dados + i);
    }
  }
  return img;
}
/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img) {
  if (img->type == INT) {
    for (int i = 0; i < img->altura * img->largura; i++) {
      printf("%d ", ((int *)img->dados)[i]);
      if (i % img->largura == 0 && i != 0) {
        printf("\n");
      }
    }
  } else if (img->type == FLOAT) {
    for (int i = 0; i < img->altura * img->largura; i++) {
      printf("%.2f ", ((float *)img->dados)[i]);
      if (i % img->largura == 0 && i != 0) {
        printf("\n");
      }
    }
  }
}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img) {
  free(img->dados);
  free(img);
}

#include "histograma.h"
#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar um Histograma.
 */
struct tHistograma {
  Imagem *img;
  int intervalos;
  int *calculo;
  int divisao;
};

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos) {
  Histograma *hist = (Histograma *)malloc(sizeof(Histograma));
  hist->img = img;
  hist->intervalos = nIntervalos;
  hist->calculo = (int *)calloc(nIntervalos, sizeof(int));
  hist->divisao = 256 / nIntervalos + (256 % nIntervalos != 0);
  if (ObterTipoImagem(img) == INT) {
    int *dados = (int *)ObterDadosImagem(img);
    for (int i = 0; i < ObterAltura(img) * ObterLargura(img); i++) {
      hist->calculo[dados[i] / hist->divisao]++;
    }
  } else if (ObterTipoImagem(img) == FLOAT) {
    float *dados = (float *)ObterDadosImagem(img);
    for (int i = 0; i < ObterAltura(img) * ObterLargura(img); i++) {
      int temp = dados[i] * 255;
      hist->calculo[temp / hist->divisao]++;
    }
  }
  return hist;
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma) {
  int div = 0, count = 0;
  while (div < 255) {
    printf("[%d, %d): %d\n", div, div + histograma->divisao,
           histograma->calculo[count]);
    div += histograma->divisao;
    count++;
  }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma) {
  free(histograma->calculo);
  free(histograma);
}

#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>

struct tHistograma {
  int nIntervalos;
  int *nPorIntervalo;
  int divisoes;
};

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos) {
  Histograma *hist = (Histograma *)malloc(sizeof(Histograma));
  hist->nIntervalos = nIntervalos;
  hist->nPorIntervalo = (int *)calloc(nIntervalos, sizeof(int));
  hist->divisoes = 256 / nIntervalos + (256 % nIntervalos != 0);

  switch (ObterTipoImagem(img)) {
  case FLOAT: {
    float *dados = (float *)ObterDadosImagem(img);
    for (int i = 0; i < ObterAlturaImagem(img) * ObterLarguraImagem(img); i++) {
      int temp = dados[i] * 255;
      hist->nPorIntervalo[temp / hist->divisoes]++;
    }
    break;
  }
  case INT: {
    int *dados = (int *)ObterDadosImagem(img);
    for (int i = 0; i < ObterAlturaImagem(img) * ObterLarguraImagem(img); i++) {
      hist->nPorIntervalo[dados[i] / hist->divisoes]++;
    }
    break;
  }
  }

  return hist;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma) {
  int count = 0;
  for (int i = 0; i < histograma->nIntervalos; i++) {
    printf("[%d, %d): %d\n", count, count + histograma->divisoes,
           histograma->nPorIntervalo[i]);
    count += histograma->divisoes;
  }
}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma) {
  free(histograma->nPorIntervalo);
  free(histograma);
}

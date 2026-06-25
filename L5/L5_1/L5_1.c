#include <math.h>
#include <stdio.h>

void InicializaVetor(int vetor[], int tam) {
  int i = 0;
  for (i = 0; i < tam; i++) {
    scanf("%d", &vetor[i]);
  }
}

int RetornaMaiorValor(int vetor[], int tam) {
  int i = 0, maior = vetor[0];
  for (i = 0; i < tam; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
  }
  return maior;
}

int RetornaMenorValor(int vetor[], int tam) {
  int i = 0, menor = vetor[0];
  for (i = 0; i < tam; i++) {
    if (vetor[i] < menor) {
      menor = vetor[i];
    }
  }
  return menor;
}

float CalculaMedia(int vetor[], int tam) {
  int i = 0;
  float soma = 0;
  for (i = 0; i < tam; i++) {
    soma += vetor[i];
  }
  return soma / tam;
}

float CalculaDP(int vetor[], int tam) {
  int i = 0;
  float media = CalculaMedia(vetor, tam), soma = 0;
  for (i = 0; i < tam; i++) {
    soma += pow((vetor[i] - media), 2);
  }
  return sqrt(soma / tam);
}

int main() {
  int tam, acimaDaMedia = 0, reprovados = 0, i = 0, menor, maior;
  float media, dp;
  scanf("%d", &tam);
  int notas[tam];
  InicializaVetor(notas, tam);

  menor = RetornaMenorValor(notas, tam);
  maior = RetornaMaiorValor(notas, tam);
  media = CalculaMedia(notas, tam);
  dp = CalculaDP(notas, tam);
  for (i = 0; i < tam; i++) {
    if (notas[i] > media) {
      acimaDaMedia++;
    }
    if (notas[i] < 70) {
      reprovados++;
    }
  }

  printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, "
         "REPROV:%d",
         menor, maior, media, dp, acimaDaMedia, reprovados);
  return 0;
}

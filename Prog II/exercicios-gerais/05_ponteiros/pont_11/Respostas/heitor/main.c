#include "calculadora.h"
#include <stdio.h>

float adicao(float n1, float n2) { return n1 + n2; }

float subtracao(float n1, float n2) { return n1 - n2; }

float multiplicacao(float n1, float n2) { return n1 * n2; }

float divisao(float n1, float n2) { return n1 / n2; }

int main() {
  char operacao;

  while (scanf("%c\n", &operacao) && operacao != 'f') {
    float num1, num2;
    scanf("%f %f\n", &num1, &num2);
    switch (operacao) {
    case 'a':
      printf("%.2f + %.2f = %.2f\n", num1, num2, Calcular(num1, num2, *adicao));
      break;
    case 's':
      printf("%.2f - %.2f = %.2f\n", num1, num2,
             Calcular(num1, num2, *subtracao));
      break;
    case 'm':
      printf("%.2f x %.2f = %.2f\n", num1, num2,
             Calcular(num1, num2, *multiplicacao));
      break;
    case 'd':
      printf("%.2f / %.2f = %.2f\n", num1, num2,
             Calcular(num1, num2, *divisao));
      break;
    }
  }
  return 0;
}

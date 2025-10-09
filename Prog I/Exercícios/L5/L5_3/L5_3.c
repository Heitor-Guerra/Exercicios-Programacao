#include <stdio.h>

int ValorAbsoluto(int n) {
  if (n < 0) {
    return -n;
  }
  return n;
}

int VerificaMaiorDiferenca(int vetor[], int tam) {
  int i = 0, maiorDiferenca = 0;
  for (i = 1; i < tam; i++) {
    if (ValorAbsoluto(vetor[i] - vetor[i - 1]) > maiorDiferenca) {
      maiorDiferenca = ValorAbsoluto(vetor[i] - vetor[i - 1]);
    }
  }
  return maiorDiferenca;
}

void InicializaVetor(int vetor[], int tam) {
  int i = 0;
  for (i = 0; i < tam; i++) {
    scanf("%d", &vetor[i]);
  }
}

int main() {
  int tam, i = 1, maiorDiferenca = 0;
  scanf("%d", &tam);
  int alturas[tam];
  InicializaVetor(alturas, tam);
  maiorDiferenca = VerificaMaiorDiferenca(alturas, tam);

  for (i = 1; i < tam; i++) {
    if (ValorAbsoluto(alturas[i] - alturas[i - 1]) == maiorDiferenca) {
      printf(" (%d %d)", i - 1, i);
    }
  }
  if (tam == 1) {
    printf("IMPOSSIVEL");
  }

  return 0;
}

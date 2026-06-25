#include <stdio.h>

#define MAXIMO 1001
#define NUM_DE_ROTULOS_DIFERENTES                                              \
  62 // 26 minusculos, 26 maiusculos, 10 algarismos (26+26+10)

void zeraVetor(int tamanho, int vetor[]) {
  int i;
  for (i = 0; i < tamanho; i++) {
    vetor[i] = 0;
  }
}

void transcreveRotulos(char rotulos[], int tamanho, int rotulosDiferentes[]) {
  int i;
  for (i = 0; rotulos[i] != '\0'; i++) {
    if (rotulos[i] >= '0' && rotulos[i] <= '9') {
      rotulosDiferentes[rotulos[i] - '0']++;
    } else if (rotulos[i] >= 'A' && rotulos[i] <= 'Z') {
      rotulosDiferentes[rotulos[i] - 'A' + 10]++;
    } else if (rotulos[i] >= 'a' && rotulos[i] <= 'z') {
      rotulosDiferentes[rotulos[i] - 'a' + 36]++;
    }
  }
}

void verificaRotulosAcimaLimite(int lim, int tamanho, int rotulos[]) {
  int i, j, semRotuloExtra = 1;
  char caracter;
  for (i = 0; i < tamanho; i++) {
    if (rotulos[i] > lim) {
      semRotuloExtra = 0;
      if (i < 10) {
        caracter = i + '0';
      } else if (i >= 10 && i < 36) {
        caracter = i + 'A' - 10;
      } else if (i >= 36) {
        caracter = i + 'a' - 36;
      }
      printf("%c: %d\n", caracter, rotulos[i]);
    }
  }
  if (semRotuloExtra) {
    printf("NENHUM");
  }
}

int main() {
  int quantidadeLimite, i;
  scanf("%d\n", &quantidadeLimite);
  char rotulos[MAXIMO];
  scanf("%s", rotulos);
  int rotulosDiferentes[NUM_DE_ROTULOS_DIFERENTES];

  zeraVetor(NUM_DE_ROTULOS_DIFERENTES, rotulosDiferentes);
  transcreveRotulos(rotulos, NUM_DE_ROTULOS_DIFERENTES, rotulosDiferentes);
  verificaRotulosAcimaLimite(quantidadeLimite, NUM_DE_ROTULOS_DIFERENTES,
                             rotulosDiferentes);

  return 0;
}

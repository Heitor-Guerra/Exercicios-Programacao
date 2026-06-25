#include "string_utils.h"
#include <stdio.h>
#define MAX_STRING 10000

void processChoice(char *string, int choice) {
  char copy[MAX_STRING];
  switch (choice) {
  case 1:
    printf("Tamanho da string: %d", string_length(string));
    return;
  case 2:
    string_copy(string, copy);
    printf("String copiada: %s", copy);
    return;
  case 3:
    string_upper(string);
    printf("String convertida para maiusculas: %s", string);
    return;
  case 4:
    string_lower(string);
    printf("String convertida para minusculas: %s", string);
    return;
  case 5:
    string_reverse(string);
    printf("String invertida: %s", string);
    return;
  case 6:
    return;
  }
}

int main() {
  char string[MAX_STRING];
  int choice = -1;
  scanf("%[^\n]", string);

  while (choice != 6) {
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
    scanf("%d", &choice);
    printf("\n");

    processChoice(string, choice);
    printf("\n\n");
  }

  return 0;
}

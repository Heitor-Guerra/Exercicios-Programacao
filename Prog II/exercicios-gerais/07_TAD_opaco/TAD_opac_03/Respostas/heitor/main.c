#include "locadora.h"
#include <stdio.h>
#include <string.h>

int main() {
  tLocadora *locadora = CriarLocadora();
  char op[10];
  while (scanf("%s", op) == 1) {
    if (strcmp(op, "Cadastrar") == 0) {
      LerCadastroLocadora(locadora);
    } else if (strcmp(op, "Alugar") == 0) {
      LerAluguelLocadora(locadora);
    } else if (strcmp(op, "Devolver") == 0) {
      LerDevolucaoLocadora(locadora);
    } else if (strcmp(op, "Estoque") == 0) {
      OrdenarFilmesLocadora(locadora);
      ConsultarEstoqueLocadora(locadora);
    } else {
      continue;
    }

    printf("\n");
  }

  ConsultarLucroLocadora(locadora);

  DestruirLocadora(locadora);
  return 0;
}

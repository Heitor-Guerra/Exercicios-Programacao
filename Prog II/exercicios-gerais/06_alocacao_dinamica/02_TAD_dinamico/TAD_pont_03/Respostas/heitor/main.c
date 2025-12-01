#include "locadora.h"
#include <stdio.h>
#include <string.h>

int main() {
  tLocadora *loc = CriarLocadora();
  char operacao[10];

  while (scanf("%s\n", operacao) != EOF) {
    if (strcmp(operacao, "Cadastrar") == 0) {
      LerCadastroLocadora(loc);
    } else if (strcmp(operacao, "Alugar") == 0) {
      LerAluguelLocadora(loc);
    } else if (strcmp(operacao, "Devolver") == 0) {
      LerDevolucaoLocadora(loc);
    } else if (strcmp(operacao, "Estoque") == 0) {
      OrdenarFilmesLocadora(loc);
      ConsultarEstoqueLocadora(loc);
    }
    printf("\n");
  }

  ConsultarLucroLocadora(loc);

  DestruirLocadora(loc);
  return 0;
}

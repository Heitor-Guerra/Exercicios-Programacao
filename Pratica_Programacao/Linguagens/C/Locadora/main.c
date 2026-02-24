#include "locadora.h"
#include <stdio.h>
#include <string.h>

#define MAX_CARACTER_OPERACAO 20

int main() {
  char operacao[MAX_CARACTER_OPERACAO];
  tLocadora locadora = criarLocadora();

  while (scanf("%s", operacao) != EOF) {
    if (strcmp(operacao, "Cadastrar") == 0) {
      locadora = lerCadastroLocadora(locadora);
    } else if (strcmp(operacao, "Alugar") == 0) {
      locadora = lerAluguelLocadora(locadora);
    } else if (strcmp(operacao, "Devolver") == 0) {
      locadora = lerDevolucaoLocadora(locadora);
    } else if (strcmp(operacao, "Estoque") == 0) {
      locadora = ordenarFilmesLocadora(locadora);
      consultarEstoqueLocadora(locadora);
    }
    puts("");
  }
  consultarLucroLocadora(locadora);
  return 0;
}

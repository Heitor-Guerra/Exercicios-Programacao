#include "loja.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_INCREMENTO_NUM_LOJAS 1

int main() {
  int numLojasAlocado, numLojasUsado = 0;
  scanf("%d\n", &numLojasAlocado);

  tLoja **lojas = (tLoja **)malloc(numLojasAlocado * sizeof(tLoja *));

  int escolha;
  while (scanf("%d\n", &escolha) == 1 && escolha != 0) {
    switch (escolha) {
    case 1: {
      int idLoja;
      float aluguel;
      scanf("%d %f\n", &idLoja, &aluguel);

      if (numLojasUsado >= numLojasAlocado) {
        numLojasAlocado += TAM_INCREMENTO_NUM_LOJAS;
        lojas = (tLoja **)realloc(lojas, numLojasAlocado * sizeof(tLoja *));
      }

      lojas[numLojasUsado] = AbreLoja(idLoja, aluguel);
      numLojasUsado++;
      break;
    }
    case 2: {
      char nome[20];
      float salario, porcentagem;
      int idLoja;
      scanf("%s %f %f\n", nome, &salario, &porcentagem);
      tVendedor *vendedor = RegistraVendedor(nome, salario, porcentagem);

      scanf("%d\n", &idLoja);
      for (int i = 0; i < numLojasUsado; i++) {
        if (VerificaIdLoja(lojas[i], idLoja)) {
          ContrataVendedor(lojas[i], vendedor);
          break;
        }
      }
      break;
    }
    case 3: {
      int idLoja;
      float valor;
      char nome[20]; //------------------Nome estatico-------------------//
      scanf("%d %s %f\n", &idLoja, nome, &valor);

      for (int i = 0; i < numLojasUsado; i++) {
        if (VerificaIdLoja(lojas[i], idLoja)) {
          RegistraVenda(lojas[i], nome, valor);
          break;
        }
      }
      break;
    }
    case 4:
      for (int i = 0; i < numLojasUsado; i++) {
        CalculaLucro(lojas[i]);
        ImprimeRelatorioLoja(lojas[i]);
      }
      break;
    }
  }

  for (int i = 0; i < numLojasUsado; i++) {
    ApagaLoja(lojas[i]);
  }
  free(lojas);

  return 0;
}

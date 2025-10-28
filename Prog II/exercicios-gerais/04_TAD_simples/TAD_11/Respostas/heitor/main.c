#include "loja.h"
#include <stdio.h>
#include <stdlib.h>

int procuraIDLojas(int numLojas, tLoja *lojas, int id) {
  for (int i = 0; i < numLojas; i++) {
    if (VerificaIdLoja(lojas[i], id)) {
      return i;
    }
  }
  puts("Erro: ID da loja inexistente!!!!\nSaindo.");
  exit(1);
}

int main() {
  int quantidadeLojas = 0, lojasRegistradas = 0, choice = 0;
  scanf("%d\n", &quantidadeLojas);
  tLoja lojas[quantidadeLojas];

  while (scanf("%d\n", &choice) && choice != 0) {
    switch (choice) {
    case 1: {
      int id;
      float aluguel;
      scanf("%d %f\n", &id, &aluguel);
      lojas[lojasRegistradas] = AbreLoja(id, aluguel);
      lojasRegistradas++;
      break;
    }
    case 2: {
      char nome[50];
      float salario, pComissao;
      int id;
      scanf("%s %f %f\n", nome, &salario, &pComissao);
      scanf("%d\n", &id);

      tVendedor vendedor = RegistraVendedor(nome, salario, pComissao);
      lojas[procuraIDLojas(lojasRegistradas, lojas, id)] = ContrataVendedor(
          lojas[procuraIDLojas(lojasRegistradas, lojas, id)], vendedor);
      break;
    }
    case 3: {
      int id;
      char nome[50];
      float venda;
      scanf("%d %s %f", &id, nome, &venda);

      lojas[procuraIDLojas(lojasRegistradas, lojas, id)] = RegistraVenda(
          lojas[procuraIDLojas(lojasRegistradas, lojas, id)], nome, venda);
      break;
    }
    case 4:
      for (int i = 0; i < lojasRegistradas; i++) {
        lojas[i] = CalculaLucro(lojas[i]);
        ImprimeRelatorioLoja(lojas[i]);
        puts("");
      }
      break;
    }
  }

  return 0;
}

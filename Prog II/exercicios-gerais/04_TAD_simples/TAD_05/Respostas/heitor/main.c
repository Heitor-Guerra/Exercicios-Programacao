#include "conta.h"
#include <stdio.h>

int main() {
  short int numContas;
  scanf("%hd", &numContas);
  tConta contas[numContas];

  short int contasCriadas = 0;

  short int escolha;
  while (scanf("%hd\n", &escolha) && escolha != 0) {
    switch (escolha) {
    case 1: {
      int contaParaSaque;
      float saque;
      scanf("%d %f\n", &contaParaSaque, &saque);
      for (int i = 0; i < contasCriadas; i++) {
        if (VerificaConta(contas[i], contaParaSaque)) {
          contas[i] = SaqueConta(contas[i], saque);
        }
      }
      break;
    }
    case 2: {
      int contaParaDeposito;
      float deposito;
      scanf("%d %f\n", &contaParaDeposito, &deposito);
      for (int i = 0; i < contasCriadas; i++) {
        if (VerificaConta(contas[i], contaParaDeposito)) {
          contas[i] = DepositoConta(contas[i], deposito);
        }
      }
      break;
    }
    case 3: {
      char nome[20];
      char cpf[20];
      int numero;
      scanf("%s %s %d\n", nome, cpf, &numero);
      tUsuario user = CriaUsuario(nome, cpf);
      if (contasCriadas < numContas) {
        contas[contasCriadas] = CriaConta(numero, user);
        contasCriadas++;
      } else {
        puts("Limite de contas alcancado!");
      }
      break;
    }
    case 4:
      puts("===| Imprimindo Relatorio |===");
      for (int i = 0; i < numContas; i++) {
        ImprimeConta(contas[i]);
        printf("\n");
      }
      break;
    }
  }

  return 0;
}

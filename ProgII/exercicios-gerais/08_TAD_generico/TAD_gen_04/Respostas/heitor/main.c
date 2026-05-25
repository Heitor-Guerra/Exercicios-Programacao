#include "agencia.h"
#include "banco.h"
#include "conta.h"
#include <stdio.h>

int main() {
  tBanco *banco = CriaBanco();
  LeBanco(banco);

  char escolha;
  while (scanf("%c\n", &escolha) == 1 && escolha != 'F') {
    switch (escolha) {
    case 'A': {
      tAgencia *temp = CriaAgencia();
      LeAgencia(temp);
      AdicionaAgencia(banco, temp);
      break;
    }
    case 'C': {
      tConta *temp = CriaConta();
      LeConta(temp);
      int num;
      scanf("%d\n", &num);
      InsereContaBanco(banco, num, temp);
      break;
    }
    }
  }
  ImprimeRelatorioBanco(banco);
  DestroiBanco(banco);
  return 0;
}

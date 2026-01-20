#include "banco.h"
#include <stdio.h>

int main() {
  tBanco *banco = CriaBanco();
  LeBanco(banco);

  char opcao;
  while (scanf("%c\n", &opcao) == 1 && opcao != 'F') {
    switch (opcao) {
    case 'A': {
      tAgencia *temp = CriaAgencia();
      LeAgencia(temp);
      AdicionaAgencia(banco, temp);
      break;
    }
    case 'C': {
      tConta *temp = CriaConta();
      LeConta(temp);
      int numAgencia;
      scanf("%d\n", &numAgencia);
      InsereContaBanco(banco, numAgencia, temp);
      break;
    }
    }
  }
  ImprimeRelatorioBanco(banco);
  DestroiBanco(banco);

  return 0;
}

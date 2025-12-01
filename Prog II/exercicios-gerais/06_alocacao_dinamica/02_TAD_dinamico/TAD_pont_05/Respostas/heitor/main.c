#include "banco.h"
#include <stdio.h>

int main() {
  tBanco *banco = CriaBanco();
  char escolha;

  while (scanf("%c\n", &escolha) == 1 && escolha != 'F' && escolha != EOF) {
    switch (escolha) {
    case 'A':
      AbreContaBanco(banco);
      break;
    case 'D':
      DepositoContaBanco(banco);
      break;
    case 'S':
      SaqueContaBanco(banco);
      break;
    case 'T':
      TransferenciaContaBanco(banco);
      break;
    case 'R':
      ImprimeRelatorioBanco(banco);
      break;
    }
  }

  DestroiBanco(banco);
  return 0;
}

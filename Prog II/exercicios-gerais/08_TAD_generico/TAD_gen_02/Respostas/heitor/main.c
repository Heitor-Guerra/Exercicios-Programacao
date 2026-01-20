#include "gerenciadorpacotes.h"
#include "pacote.h"
#include <stdio.h>

int main() {
  tGerenciador *ger = CriaGerenciador();
  printf("\n");
  int choice;
  while (scanf("%d\n", &choice) == 1 && choice != 3) {
    printf("Escolha uma opcao:\n");
    printf("\t(1) Cadastrar um novo pacote\n");
    printf("\t(2) Imprimir um pacote especifico\n");
    printf("\t(3) Imprimir todos os pacotes e sair\n");

    switch (choice) {
    case 1: {
      printf("Digite o tipo (0-char, 1-int) e o numero de elementos do "
             "pacote/mensagem:\n");
      Type tipo;
      int numE;
      scanf("%d %d\n", &tipo, &numE);
      if (tipo != INT && tipo != CHAR) {
        printf("Digite um tipo valido!\n");
        break;
      }
      tPacote *pac = CriaPacote(tipo, numE);
      LePacote(pac);
      AdicionaPacoteNoGerenciador(ger, pac);
      break;
    }
    case 2: {
      int index;
      scanf("%d\n", &index);
      ImprimirPacoteNoIndice(ger, index);
      break;
    }
    default:
      printf("Escolha uma opcao valida para o menu!\n");
      break;
    }
  }
  printf("Escolha uma opcao:\n");
  printf("\t(1) Cadastrar um novo pacote\n");
  printf("\t(2) Imprimir um pacote especifico\n");
  printf("\t(3) Imprimir todos os pacotes e sair\n");

  ImprimirTodosPacotes(ger);
  DestroiGerenciador(ger);

  return 0;
}

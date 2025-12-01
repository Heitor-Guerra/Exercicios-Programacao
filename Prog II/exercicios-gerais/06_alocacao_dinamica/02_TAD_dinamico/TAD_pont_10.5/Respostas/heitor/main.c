#include "biblioteca.h"
#include <stdio.h>

int main() {
  int numOp;
  scanf("%d\n", &numOp);

  tBiblioteca *bibli = InicializarBiblioteca();

  printf("Lista de operacoes:\n");
  printf("1 - Cadastrar livros.\n");
  printf("2 - Remover livros.\n");
  printf("3 - Listar todos os livros cadastrados.\n\n");

  int escolha;
  for (int i = 0; i < numOp; i++) {
    scanf("%d\n", &escolha);
    switch (escolha) {
    case 1: {
      tLivros *livro = CriaLivro();
      LerLivro(livro);
      AdicionarLivroNaBiblioteca(bibli, livro);
      break;
    }
    case 2: {
      char nomeLivro[100];
      scanf("%[^\n]\n", nomeLivro);
      RemoverLivroDaBiblioteca(bibli, nomeLivro);
      break;
    }
    case 3:
      ListarLivrosDaBiblioteca(bibli);
      break;
    default:
      printf("Operacao invalida!\n");
      ApagaBiblioteca(bibli);
      return 1;
    }
  }

  ApagaBiblioteca(bibli);
  return 0;
}

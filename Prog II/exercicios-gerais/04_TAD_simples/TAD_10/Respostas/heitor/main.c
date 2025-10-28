#include "biblioteca.h"
#include <stdio.h>

int main() {
  int numEscolhas;
  int escolha;
  scanf("%d\n", &numEscolhas);
  tBiblioteca biblioteca = inicializarBiblioteca();

  puts("Lista de operacoes:");
  puts("1 - Cadastrar livros.");
  puts("2 - Remover livros.");
  puts("3 - Listar todos os livros cadastrados.\n");

  for (int i = 0; i < numEscolhas; i++) {
    scanf("%d\n", &escolha);
    switch (escolha) {
    case 1: {
      tLivros livro = lerLivro();
      biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
      break;
    }
    case 2: {
      char livroRemover[100];
      scanf("%[^\n]\n", livroRemover);
      biblioteca = removerLivroDaBiblioteca(biblioteca, livroRemover);
      break;
    }
    case 3:
      listarLivrosDaBiblioteca(biblioteca);
      break;
    default:
      puts("Operacao invalida!");
      return 1;
    }
    puts("");
  }

  return 0;
}

#include "livro.h"
#include <stdio.h>

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro() {
  tLivros livro;
  scanf("%[^\n]\n", livro.titulo);
  scanf("%[^\n]\n", livro.autor);
  scanf("%d\n", &livro.anoPublicacao);
  return livro;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 *
 * @param livro O livro cujos atributos serão impressos
 */
void imprimeLivro(tLivros livro) {
  printf("Titulo: %s\n", livro.titulo);
  printf("Autor: %s\n", livro.autor);
  printf("Ano de Publicacao: %4d\n", livro.anoPublicacao);
}

#include "livro.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos
 * valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros *CriaLivro() {
  tLivros *livro = (tLivros *)malloc(sizeof(tLivros));
  livro->anoPublicacao = -1;
  livro->autor = NULL;
  livro->titulo = NULL;
  return livro;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros *livro) {
  livro->titulo = (char *)malloc(100 * sizeof(char));
  livro->autor = (char *)malloc(100 * sizeof(char));
  scanf("\n%[^\n]\n", livro->titulo);
  scanf("%[^\n]\n", livro->autor);
  scanf("%d\n", &livro->anoPublicacao);
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 *
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
 */
void ImprimeLivro(tLivros *livro) {
  printf("Titulo: %s\n", livro->titulo);
  printf("Autor: %s\n", livro->autor);
  printf("Ano de Publicacao: %d\n", livro->anoPublicacao);
}

/**
 * Função para liberar toda a memória alocada por um livro
 *
 * @param livro Um ponteiro para o livro cujos atributos serão
 * apagados/liberados
 */
void ApagaLivro(tLivros *livro) {
  free(livro->titulo);
  free(livro->autor);
  free(livro);
}

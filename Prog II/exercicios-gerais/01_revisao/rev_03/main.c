#include <stdio.h>

void leLivros(int numLivros, int livros[]) {
  int i;
  for (i = 0; i < numLivros; i++) {
    scanf("%d", &livros[i]);
  }
}

int main() {
  int numLivros, i, j, livroUnico, semLivroUnico = 1;
  scanf("%d", &numLivros);
  int idLivros[numLivros];

  leLivros(numLivros, idLivros);

  for (i = 0; i < numLivros; i++) {
    livroUnico = 1;
    for (j = 0; j < numLivros; j++) {
      if (idLivros[j] == idLivros[i] && j != i) {
        livroUnico = 0;
        semLivroUnico = 0;
      }
    }
    if (livroUnico) {
      printf("%d ", idLivros[i]);
    }
  }
  if (semLivroUnico) {
    printf("NENHUM");
  }

  return 0;
}

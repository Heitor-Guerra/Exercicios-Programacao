#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char nome[32];
  Vector *disciplinas;
} Professor;

typedef struct {
  char nome[32];
  int numMatriculados;
  int numAprovados;
} Disciplina;

float calcula_perc_reprovacao(Disciplina *d) {
  return (d->numMatriculados - d->numAprovados) / (float)d->numMatriculados;
}

float calcula_media_reprovacao_prof(Professor *p) {
  float media = 0;
  for (int i = 0; i < vector_size(p->disciplinas); i++) {
    Disciplina *d = (Disciplina *)vector_get(p->disciplinas, i);
    media += calcula_perc_reprovacao(d);
    free(d);
  }
  return media / vector_size(p->disciplinas);
}

int main() {
  Vector *professores = vector_construct();
  int numProfs;
  scanf("%d\n", &numProfs);
  float mediaTotal = 0;

  for (int i = 0; i < numProfs; i++) {
    Professor *p = (Professor *)malloc(sizeof(Professor));
    p->disciplinas = vector_construct();
    int numDisciplinas;

    scanf("%[^\n]\n", p->nome);
    scanf("%d\n", &numDisciplinas);

    float mediaP = 0;
    for (int j = 0; j < numDisciplinas; j++) {
      Disciplina *d = (Disciplina *)malloc(sizeof(Disciplina));
      scanf("%s %d %d\n", d->nome, &d->numMatriculados, &d->numAprovados);
      mediaP += calcula_perc_reprovacao(d);
      vector_push_back(p->disciplinas, d);
    }
    vector_push_back(professores, p);

    mediaP /= numDisciplinas;
    mediaTotal += mediaP;
  }
  mediaTotal /= numProfs;

  for (int i = 0; i < numProfs; i++) {
    Professor *p = (Professor *)vector_get(professores, i);
    if (calcula_media_reprovacao_prof(p) > mediaTotal) {
      printf("%s\n", p->nome);
    }
    vector_destroy(p->disciplinas);
    free(p);
  }
  vector_destroy(professores);

  return 0;
}

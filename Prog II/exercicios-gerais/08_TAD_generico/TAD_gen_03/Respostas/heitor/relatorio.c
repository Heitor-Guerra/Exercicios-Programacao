#include "relatorio.h"
#include "aluno.h"
#include "vector.h"
#include <stdio.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e
 * porcentagem de cada gênero.
 *
 * @param alunos Ponteiro para o vetor de alunos.
 */
void ImprimeRelatorio(Vector *alunos) {
  float media = 0, aprovados = 0, m = 0, f = 0, o = 0;
  int numA = VectorSize(alunos);
  for (int i = 0; i < numA; i++) {
    tAluno *aluno = (tAluno *)VectorGet(alunos, i);
    media += GetNotaAluno(aluno);
    if (GetNotaAluno(aluno) >= 6) {
      aprovados++;
    }
    switch (GetGeneroAluno(aluno)) {
    case 'M':
      m++;
      break;
    case 'F':
      f++;
      break;
    case 'O':
      o++;
      break;
    }
  }
  printf("Media das notas: %.2f\n", media / numA);
  printf("Porcentagem de alunos aprovados: %.2f%%\n", aprovados * 100 / numA);
  printf("Porcentagem de cada genero:\n");
  printf("Masculino: %.2f%%\n", m * 100 / numA);
  printf("Feminino: %.2f%%\n", f * 100 / numA);
  printf("Outro: %.2f%%\n", o * 100 / numA);
}

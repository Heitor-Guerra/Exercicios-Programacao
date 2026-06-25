#include "tDepartamento.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do
 * departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do
 * departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do
 * departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do
 * departamento
 */
tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3,
                               char *nome, int m1, int m2, int m3,
                               char *diretor) {
  tDepartamento dep = {.m1 = m1, .m2 = m2, .m3 = m3};
  strcpy(dep.curso1, curso1);
  strcpy(dep.curso2, curso2);
  strcpy(dep.curso3, curso3);
  strcpy(dep.diretor, diretor);
  strcpy(dep.nome, nome);
  return dep;
}
/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto) {
  printf("\nDepartamento: %s\n", depto.nome);
  printf("\tDiretor: %s\n", depto.diretor);
  printf("\t1o curso: %s\n", depto.curso1);
  printf("\tMedia do 1o curso: %d\n", depto.m1);
  printf("\t2o curso: %s\n", depto.curso2);
  printf("\tMedia do 2o curso: %d\n", depto.m2);
  printf("\t3o curso: %s\n", depto.curso3);
  printf("\tMedia do 3o curso: %d\n", depto.m3);
  printf("\tMedia dos cursos: %.2f\n", (depto.m1 + depto.m2 + depto.m3) / 3.0);
}

void TrocaSeForMaior(tDepartamento *deps, int num_deptos,
                     tDepartamento *depParaTrocar) {
  int indiceMaior = 0;
  float mediaMaior = 0;
  for (int i = 0; i < num_deptos; i++) {
    float media = (deps[i].m1 + deps[i].m2 + deps[i].m3) / 3.0;
    if (media > mediaMaior) {
      indiceMaior = i;
      mediaMaior = media;
    }
  }

  float mediaParaTrocar = (deps->m1 + deps->m2 + deps->m3) / 3.0;
  if (mediaMaior > mediaParaTrocar) {
    tDepartamento temp = deps[indiceMaior];
    deps[indiceMaior] = *depParaTrocar;
    *depParaTrocar = temp;
  }
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um
 * dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos) {
  tDepartamento *pointer = vetor_deptos;
  for (int i = 0; i < num_deptos; i++) {
    TrocaSeForMaior(vetor_deptos, num_deptos - i, vetor_deptos + i);
    vetor_deptos++;
  }
}

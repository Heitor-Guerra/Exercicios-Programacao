#include "database.h"
#include "aluno.h"
#include "professor.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Database {
  Vector *alunos;
  Vector *profs;
};

/**
 * @brief Cria um nova database.
 * @return Um ponteiro para a estrutura database criada. Caso a alocação falhe,
 * a função termina o programa.
 */
tDatabase *CriaDatabase() {
  tDatabase *db = (tDatabase *)malloc(sizeof(tDatabase));
  db->alunos = VectorConstruct();
  db->profs = VectorConstruct();

  return db;
}

void DestroiADatabase(DataType val) {
  tAluno *a = (tAluno *)val;
  DestroiAluno(a);
}

void DestroiPDatabase(DataType val) {
  tProfessor *p = (tProfessor *)val;
  DestroiProfessor(p);
}

/**
 * @brief Destroi uma database.
 * @param db Ponteiro para a estrutura da database a ser destruída.
 */
void DestroiDatabase(tDatabase *db) {
  VectorDestroy(db->alunos, DestroiADatabase);
  VectorDestroy(db->profs, DestroiPDatabase);
  free(db);
}

/**
 * @brief Lê uma database da entrada padrão.
 * @param db Ponteiro para a estrutura da database a ser lida.
 */
void LeDatabase(tDatabase *db) {
  int numA, numP;
  scanf("%d", &numA);
  for (int i = 0; i < numA; i++) {
    VectorPushBack(db->alunos, LeAluno());
  }
  scanf("%d", &numP);
  for (int i = 0; i < numP; i++) {
    VectorPushBack(db->profs, LeProfessor());
  }
}

/**
 * @brief Ordena uma database, primeiro os alunos e depois os professores, de
 * acordo com o nome.
 * @param db Ponteiro para a estrutura da database a ser ordenada.
 */
void OrdenaDatabase(tDatabase *db) {
  int done = 0;
  while (!done) {
    for (int i = 1; i < VectorSize(db->alunos); i++) {
      tAluno *a1 = VectorGet(db->alunos, i - 1);
      tAluno *a2 = VectorGet(db->alunos, i);
      if (ComparaNomeAluno(a1, a2) > 0) {
        VectorSwap(db->alunos, i - 1, i);
      }
    }
    done = 1;
    for (int i = 1; i < VectorSize(db->alunos); i++) {
      tAluno *a1 = VectorGet(db->alunos, i - 1);
      tAluno *a2 = VectorGet(db->alunos, i);
      if (ComparaNomeAluno(a1, a2) > 0) {
        done = 0;
        break;
      }
    }
  }

  done = 0;

  while (!done) {
    for (int i = 1; i < VectorSize(db->profs); i++) {
      tProfessor *a1 = VectorGet(db->profs, i - 1);
      tProfessor *a2 = VectorGet(db->profs, i);
      if (ComparaNomeProfessor(a1, a2) > 0) {
        VectorSwap(db->profs, i - 1, i);
      }
    }
    done = 1;
    for (int i = 1; i < VectorSize(db->profs); i++) {
      tProfessor *a1 = VectorGet(db->profs, i - 1);
      tProfessor *a2 = VectorGet(db->profs, i);
      if (ComparaNomeProfessor(a1, a2) > 0) {
        done = 0;
        break;
      }
    }
  }
}

/**
 * @brief Salva uma database em um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser salva.
 * @param file Ponteiro para o arquivo onde a database será salva.
 * @return Um inteiro indicando o total de bytes salvos.
 */
int SalvarDatabase(tDatabase *db, FILE *file) {
  int numA = VectorSize(db->alunos);
  int numP = VectorSize(db->profs);
  int total = 0;

  fwrite(&numA, sizeof(int), 1, file);
  total += sizeof(int);
  for (int i = 0; i < numA; i++) {
    total += SalvaAluno(VectorGet(db->alunos, i), file);
  }

  fwrite(&numP, sizeof(int), 1, file);
  total += sizeof(int);
  for (int i = 0; i < numP; i++) {
    total += SalvaProfessor(VectorGet(db->profs, i), file);
  }
  return total;
}

/**
 * @brief Carrega uma database de um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser carregada.
 * @param file Ponteiro para o arquivo de onde a database será carregada.
 * @return Um inteiro indicando o total de bytes lidos.
 */
int CarregaDatabase(tDatabase *db, FILE *file) {
  int numA;
  int numP;
  int total = 0;

  fread(&numA, sizeof(int), 1, file);
  total += sizeof(int);
  for (int i = 0; i < numA; i++) {
    tAluno *temp = CriaAluno("temp", "temp", "temp", 0, 0);
    total += CarregaAluno(temp, file);
    VectorPushBack(db->alunos, temp);
  }

  fread(&numP, sizeof(int), 1, file);
  total += sizeof(int);
  for (int i = 0; i < numP; i++) {

    tProfessor *temp = CriaProfessor("temp", "temp", "temp");
    total += CarregaProfessor(temp, file);
    VectorPushBack(db->profs, temp);
  }
  return total;
}

/**
 * @brief Imprime uma database, primeiro os alunos e depois os professores.
 * Apenas os nomes são impressos.
 * @param db Ponteiro para a estrutura da database a ser impressa.
 */
void ImprimeDatabase(tDatabase *db) {
  OrdenaDatabase(db);
  printf("Alunos:\n");
  for (int i = 0; i < VectorSize(db->alunos); i++) {
    ImprimeNomeAluno(VectorGet(db->alunos, i));
  }

  printf("\nProfessores:\n");
  for (int i = 0; i < VectorSize(db->profs); i++) {
    ImprimeNomeProfessor(VectorGet(db->profs, i));
  }
}

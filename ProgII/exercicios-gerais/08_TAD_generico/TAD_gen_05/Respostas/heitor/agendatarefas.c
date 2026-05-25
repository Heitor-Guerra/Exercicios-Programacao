#include "agendatarefas.h"
#include <stdlib.h>

typedef struct tarefa {
  void *dado;
  int prioridade;
  void (*executa)(void *);
  void (*destroi)(void *);
} tTarefa;

struct agendatarefas {
  tTarefa **tarefas;
  int numTarefas;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de
 * Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tTarefa *CriaTarefa(int prioridade, void *dado, void (*executa)(void *),
                    void (*destroi)(void *)) {
  tTarefa *tarefa = (tTarefa *)malloc(sizeof(tTarefa));
  tarefa->dado = dado;
  tarefa->prioridade = prioridade;
  tarefa->executa = executa;
  tarefa->destroi = destroi;
  return tarefa;
}

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de
 * Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas *CriaAgendaDeTarefas(int numElem) {
  tAgendaTarefas *agenda = (tAgendaTarefas *)malloc(sizeof(tAgendaTarefas));
  agenda->tarefas = (tTarefa **)malloc(numElem * sizeof(tTarefa *));
  agenda->numTarefas = 0;
  return agenda;
}

/**
 * @brief Destroi a tarefa (libera a memória)
 *
 * @param tar - A tarefa que terá seu conteúdo liberado/destruído
 */
void DestroiTarefa(tTarefa *tar) {
  tar->destroi(tar->dado);
  free(tar);
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas *tar) {
  for (int i = 0; i < tar->numTarefas; i++) {
    DestroiTarefa(tar->tarefas[i]);
  }
  free(tar->tarefas);
  free(tar);
}

/**
 * @brief Compara duas tarefas pela prioridade
 *
 * @param tar1 Primeira tarefa
 *
 * @param tar2 Segunda tarefa
 *
 * @return Um número positivo se a prioridade do primeiro for menor que a do
 * segunda, negativo se for maior ou 0 se for igual
 */
int comparaPrioridadeTarefa(const void *tar1, const void *tar2) {
  tTarefa *t1 = *(tTarefa **)tar1;
  tTarefa *t2 = *(tTarefa **)tar2;
  return t2->prioridade - t1->prioridade;
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for
 * a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for
 * a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa,
                            void (*executa)(void *), void (*destroi)(void *)) {
  tTarefa *temp = CriaTarefa(prioridade, tarefa, executa, destroi);
  tar->tarefas[tar->numTarefas] = temp;
  tar->numTarefas++;
  qsort(tar->tarefas, tar->numTarefas, sizeof(tTarefa *),
        comparaPrioridadeTarefa);
}

/**
 * @brief Executa a tarefa passada como
 * parâmetro.
 *
 * @param tar tarefa
 *
 */
void ExecutarTarefa(tTarefa *tar) { tar->executa(tar->dado); }

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como
 * parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas *tar) {
  for (int i = 0; i < tar->numTarefas; i++) {
    ExecutarTarefa(tar->tarefas[i]);
  }
}

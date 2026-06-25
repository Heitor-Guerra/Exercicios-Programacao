#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct impr {
  char *mensagem;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 *
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr *CriaTarefaImprimir(char *msg) {
  tImpr *mens = (tImpr *)malloc(sizeof(tImpr));
  mens->mensagem = (char *)malloc((strlen(msg) + 1) * sizeof(char));
  strcpy(mens->mensagem, msg);
  return mens;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp) {
  tImpr *msg = (tImpr *)imp;
  printf("\n%s", msg->mensagem);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp) {
  tImpr *msg = (tImpr *)imp;
  free(msg->mensagem);
  free(imp);
}

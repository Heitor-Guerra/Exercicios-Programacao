#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

char *leMensagem() {
  char *mensagem = NULL;
  int size = 0;
  char character;
  while (scanf("%c", &character) == 1 && character != '\n' &&
         character != EOF) {
    mensagem = (char *)realloc(mensagem, (size + 1) * sizeof(char));
    mensagem[size] = character;
    size++;
  }
  mensagem = (char *)realloc(mensagem, (size + 1) * sizeof(char));
  mensagem[size] = '\0';
  return mensagem;
}

int main() {
  int numTarefas;
  printf("Digite o numero de tarefas: ");
  scanf("%d\n", &numTarefas);

  tAgendaTarefas *tarefas = CriaAgendaDeTarefas(numTarefas);
  for (int i = 0; i < numTarefas; i++) {
    int prioridade;
    char tarefa;
    scanf("%d %c ", &prioridade, &tarefa);

    switch (tarefa) {
    case 'I': {
      char *mensagem = leMensagem();
      tImpr *impr = CriaTarefaImprimir(mensagem);
      CadastraTarefaNaAgenda(tarefas, prioridade, impr, ExecutaTarefaImprimir,
                             DestroiTarefaImprimir);
      free(mensagem);
      break;
    }
    case 'M': {
      float n1, n2;
      scanf("%f %f\n", &n1, &n2);
      tMult *mult = CriaTarefaMultiplicar(n1, n2);
      CadastraTarefaNaAgenda(tarefas, prioridade, mult,
                             ExecutaTarefaMultiplicar,
                             DestroiTarefaMultiplicar);
      break;
    }
    case 'S': {
      float n1, n2;
      scanf("%f %f\n", &n1, &n2);
      tSoma *soma = CriaTarefaSoma(n1, n2);
      CadastraTarefaNaAgenda(tarefas, prioridade, soma, ExecutaTarefaSoma,
                             DestroiTarefaSoma);
      break;
    }
    default:
      printf("\nDigite um tipo de tarefa suportado (I/S/M))");
      scanf("%*[^\n]\n");
      i--;
      break;
    }
  }

  ExecutarTarefasDaAgenda(tarefas);
  DestroiAgendaDeTarefas(tarefas);
  return 0;
}

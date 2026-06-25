#include "atendimento.h"
#include "frame.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char escolha[10];
  int repeticoes;
  scanf("%s", escolha);
  scanf("\n%d", &repeticoes);

  if (strcmp(escolha, "SENHAS") == 0) {
    Queue *senhas = queue_constructor(10);
    for (int i = 0; i < repeticoes; i++) {
      char opcao[10];
      scanf("\n%s", opcao);

      if (strcmp(opcao, "ADICIONAR") == 0) {

        char nome[32], cpf[20];

        scanf("%s %s", nome, cpf);

        if (!queue_is_full(senhas)) {
          queue_add(senhas, atendimento_constructor(nome, cpf));
        } else {
          printf("FILA CHEIA\n");
        }

      } else if (strcmp(opcao, "CHAMAR") == 0) {
        Atendimento *data = (Atendimento *)queue_remove(senhas);
        if (data != NULL) {
          printf("%s\n", atendimento_get_nome(data));
          atendimento_destroy(data);
        }
      }
    }

    int size = queue_size(senhas);
    for (int i = 0; i < size; i++) {
      free(queue_remove(senhas));
    }

    queue_destroy(senhas);

  } else if (strcmp(escolha, "STREAMING") == 0) {

    Queue *buffer = queue_constructor(20);
    for (int i = 0; i < repeticoes; i++) {
      char opcao[10];
      scanf("\n%s", opcao);

      if (strcmp(opcao, "ADICIONAR") == 0) {

        char idV[50];
        int id;
        float timestamp;

        scanf("%s %d %f", idV, &id, &timestamp);
        if (!queue_is_full(buffer)) {
          queue_add(buffer, frame_constructor(idV, id, timestamp));
        } else {
          printf("FILA CHEIA\n");
        }

      } else if (queue_size(buffer) < 5) {

        printf("AGUARDE\n");

      } else if (strcmp(opcao, "PLAY") == 0) {
        for (int i = 0; i < 5; i++) {

          Frame *data = (Frame *)queue_remove(buffer);
          printf("ID: %d, Timestamp: %.2f\n", frame_get_frame_id(data),
                 frame_get_timestamp(data));

          frame_destroy(data);
        }
      }
    }

    int size = queue_size(buffer);
    for (int i = 0; i < size; i++) {
      free(queue_remove(buffer));
    }

    queue_destroy(buffer);
  }

  return 0;
}

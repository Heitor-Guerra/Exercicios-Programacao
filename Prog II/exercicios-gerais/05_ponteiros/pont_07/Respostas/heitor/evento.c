#include "evento.h"
#include <stdio.h>

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento *eventos, int *numEventos) {
  if (*numEventos >= MAX_EVENTOS) {
    puts("Limite de eventos atingido!");
    return;
  }
  scanf("\n%[^\n]\n", eventos[*numEventos].nome);
  scanf("%d %d %d\n", &eventos[*numEventos].dia, &eventos[*numEventos].mes,
        &eventos[*numEventos].ano);
  puts("Evento cadastrado com sucesso!");
  *numEventos += 1;
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento *eventos, int *numEventos) {
  if (*numEventos == 0) {
    puts("Nenhum evento cadastrado.");
    return;
  }
  puts("Eventos cadastrados:");
  for (int i = 0; i < *numEventos; i++) {
    printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia,
           eventos[i].mes, eventos[i].ano);
  }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento *eventos, int *numEventos) {
  int indice;
  scanf("%d", &indice);
  if (indice >= *numEventos || indice < 0) {
    puts("Indice invalido!");
    return;
  }
  scanf("%d %d %d\n", &eventos[indice].dia, &eventos[indice].mes,
        &eventos[indice].ano);
  puts("Data modificada com sucesso!");
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de
 * eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB,
                          int *numEventos) {
  if (*indiceA >= *numEventos || *indiceA < 0 || *indiceB >= *numEventos ||
      *indiceB < 0) {
    puts("Indices invalidos!");
    return;
  }
  Evento temp = eventos[*indiceA];
  eventos[*indiceA] = eventos[*indiceB];
  eventos[*indiceB] = temp;
  puts("Eventos trocados com sucesso!");
}

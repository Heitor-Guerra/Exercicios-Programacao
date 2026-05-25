#include "deque.h"
#include "heap.h"
#include "program.h"
#include "vector.h"
#include <stdio.h>
#include <string.h>

int main() {
  Heap *so = heap_construct(program_compare);
  Heap *user = heap_construct(program_compare);
  Deque *rt = deque_construct();

  Vector *progQueue = vector_construct();

  int numProg;
  scanf("%d", &numProg);

  for (int i = 0; i < numProg; i++) {
    char nome[65];
    char tipo[5];
    int prio;
    int carga;
    int inicio;

    scanf("\n%s %s %d %d %d", nome, tipo, &prio, &carga, &inicio);
    vector_push_back(progQueue,
                     program_construct(nome, tipo, prio, carga, inicio));
  }

  int idx = 0;
  int choice = 0;
  while (heap_size(so) > 0 || heap_size(user) > 0 || deque_size(rt) > 0 ||
         vector_size(progQueue) > 0) {

    // atualiza fila
    for (int i = 0; i < vector_size(progQueue); i++) {
      Program *p = (Program *)vector_get(progQueue, i);
      if (program_get_inicio(p) == idx) {
        if (strcmp(program_get_tipo(p), "USER") == 0) {
          heap_push(user, p);
        } else if (strcmp(program_get_tipo(p), "SO") == 0) {
          heap_push(so, p);
        } else if (strcmp(program_get_tipo(p), "RT") == 0) {
          deque_push_back(rt, p);
        }
        vector_remove(progQueue, i);
        i--;
      }
    }

    // roda programas
    if (deque_size(rt) > 0) {
      Program *p = (Program *)deque_pop_front(rt);
      program_carga_decrement(p);
      if (program_get_carga(p) <= 0) {
        printf("%s %d\n", program_get_name(p), idx);
        program_destroy(p);
      } else {
        program_set_fim(p, idx);
        deque_push_back(rt, p);
      }
    } else if ((choice == 0 || heap_size(user) <= 0) && heap_size(so) != 0) {
      Program *p = (Program *)heap_pop(so);
      program_carga_decrement(p);
      if (program_get_carga(p) <= 0) {
        printf("%s %d\n", program_get_name(p), idx);
        program_destroy(p);
      } else {
        program_set_fim(p, idx);
        heap_push(so, p);
      }
      choice = 1;
    } else if ((choice == 1 || heap_size(so) <= 0) && heap_size(user) != 0) {
      Program *p = (Program *)heap_pop(user);
      program_carga_decrement(p);
      if (program_get_carga(p) <= 0) {
        printf("%s %d\n", program_get_name(p), idx);
        program_destroy(p);
      } else {
        program_set_fim(p, idx);
        heap_push(user, p);
      }
      choice = 0;
    }

    idx++;
  }

  heap_destroy(so);
  heap_destroy(user);
  deque_destroy(rt);
  vector_destroy(progQueue);
  return 0;
}

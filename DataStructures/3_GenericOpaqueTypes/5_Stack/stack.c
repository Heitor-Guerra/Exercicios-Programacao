#include "stack.h"
#include <stdlib.h>

struct stack {
  Vector *v;
};

Stack *stack_construct() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->v = vector_construct();

  return s;
}

int stack_size(Stack *s) { return vector_size(s->v); }

void stack_push(Stack *s, data_type val) { vector_push_back(s->v, val); }

data_type stack_pop(Stack *s) { return vector_pop_back(s->v); }

void stack_destruct(Stack *s) {
  vector_destroy(s->v);
  free(s);
}

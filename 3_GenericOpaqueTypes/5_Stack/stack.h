#ifndef _STACK_H
#define _STACK_H

#include "vector.h"

typedef struct stack Stack;

Stack *stack_construct();

int stack_size(Stack *s);

void stack_push(Stack *s, data_type val);

data_type stack_pop(Stack *s);

void stack_destruct(Stack *s);

#endif

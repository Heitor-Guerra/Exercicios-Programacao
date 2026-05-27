#ifndef _STACK_H_
#define _STACK_H_

#include "list.h"
typedef struct Stack Stack;

Stack* stack_construct();

int stack_size(Stack* s);

void stack_push(Stack* s, data_type val);

data_type stack_pop(Stack* s);

void stack_destroy(Stack* s);

#endif
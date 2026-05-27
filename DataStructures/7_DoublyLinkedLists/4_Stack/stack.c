#include "stack.h"
#include <stdlib.h>

struct Stack {
    List * l;
};

Stack* stack_construct() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->l = list_construct();

    return s;
}

int stack_size(Stack* s) {
    return list_size(s->l);
}

void stack_push(Stack* s, data_type val) {
    list_push_front(s->l, val);
}

data_type stack_pop(Stack* s) {
    return list_pop_front(s->l);
}

void stack_destroy(Stack* s) {
    list_destroy(s->l);
    free(s);
}
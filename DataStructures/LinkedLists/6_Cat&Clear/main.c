#include "forward_list.h"
#include <stdio.h>
#include <stdlib.h>

void print(data_type val) {
    printf("%d", val);
}

int main() {
    int num = 0;
    scanf("%d", &num);
    ForwardList* l = forward_list_construct();
    for(int i = 0; i < num; i++) {
        int value;
        scanf("\n%d", &value);
        forward_list_push_front(l, value);
    }

    scanf("\n%d", &num);
    ForwardList* m = forward_list_construct();
    for(int i = 0; i < num; i++) {
        int value;
        scanf("\n%d", &value);
        forward_list_push_front(m, value);
    }

    forward_list_cat(l, m);
    forward_list_print(l, print);

    forward_list_clear(l);
    forward_list_clear(m);

    forward_list_destroy(l);
    forward_list_destroy(m);

    return 0;
}
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

    for(int i = 0; i < forward_list_size(l); i++) {
        printf("pos %d: %d\n", i, forward_list_get(l, i));
    }

    forward_list_destroy(l);

    return 0;
}
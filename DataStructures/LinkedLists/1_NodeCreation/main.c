#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    Node* head = NULL;


    for(int i = 0; i < num; i++) {
        int value;
        scanf("\n%d", &value);
        Node* node = node_construct(value, head);
        head = node;
    }

    while(head != NULL) {
        printf("%d\n", node_value(head));
        Node* newHead = node_next(head);
        free(head);
        head = newHead;
    }


    return 0;
}
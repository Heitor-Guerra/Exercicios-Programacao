
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deque.h"

int main()
{
    int n;
    int nome;

    Deque *l = deque_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char comando[20];
        scanf("\n%s", comando);
        if(strcmp(comando, "PUSH_BACK") == 0) {
            scanf("%d", &nome);
            deque_push_back(l, nome);
        } else if (strcmp(comando, "PUSH_FRONT") == 0) {
            scanf("%d", &nome);
            deque_push_front(l, nome);
        } else if (strcmp(comando, "POP_BACK") == 0) {
            int str = deque_pop_back(l);
            printf("%d\n", str);
        } else if (strcmp(comando, "POP_FRONT") == 0) {
            int str = deque_pop_front(l);
            printf("%d\n", str);
        }
    }

    // test the destroy function
    deque_destroy(l);

    return 0;
}
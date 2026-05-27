
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    int n;
    char nome[32];

    Queue *l = queue_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char comando[15];
        scanf("\n%s", comando);
        if(strcmp(comando, "ENQUEUE") == 0) {
            scanf("%s", nome);
            char* str = (char*)malloc(32*sizeof(char));
            strcpy(str, nome);
            queue_push(l, str);
        } else if (strcmp(comando, "DEQUEUE") == 0) {
            char* str = (char*)queue_pop(l);
            printf("%s\n", str);
            free(str);
        }
    }

    while(queue_size(l) > 0) {
        free(queue_pop(l));
    }
    // test the destroy function
    queue_destroy(l);

    return 0;
}
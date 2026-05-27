
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int n;
    char nome[32];

    Stack *l = stack_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char comando[5];
        scanf("\n%s", comando);
        if(strcmp(comando, "PUSH") == 0) {
            scanf("%s", nome);
            char* str = (char*)malloc(32*sizeof(char));
            strcpy(str, nome);
            stack_push(l, str);
        } else if (strcmp(comando, "POP") == 0) {
            char* str = (char*)stack_pop(l);
            printf("%s\n", str);
            free(str);
        }
    }

    while(stack_size(l) > 0) {
        free(stack_pop(l));
    }
    // test the destroy function
    stack_destroy(l);

    return 0;
}
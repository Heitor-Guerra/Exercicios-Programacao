#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    scanf("%d", &numero);
    char *ch = (char*)&numero;

    for(int i = 0; i < 4; i++) {
        printf("%d\n", (int)*ch);
        ch++;
    }

    return 0;
}
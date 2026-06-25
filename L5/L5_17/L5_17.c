#include <stdio.h>

#define TAMANHO_MAXIMO 500


int main() {
    char Strings[TAMANHO_MAXIMO][TAMANHO_MAXIMO];
    int i = 0;
    char aux = 0;

    while(1) {
        if(scanf(" %[a-z||A-Z] ", Strings[i]) == 1) {
            i++;
        }
        else {
            if (scanf("%c", &aux) == EOF) {
                break;
            }
        }
    }

    for(i -= 1; i >= 0; i--) {
        printf("%s ", Strings[i]);
    }
    return 0;
}
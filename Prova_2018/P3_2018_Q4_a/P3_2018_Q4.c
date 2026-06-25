#include <stdio.h>

int ContaLetraPalavra(char * string) {
    int i;
    for(i = 0; string[i] != '\0'; i++) {}
    return i;
}

void IgualaString1e2(char * string1, char string2[]) {
    int i;
    for(i = 0; string1[i] != '\0'; i++) {
        string2[i] = string1[i];
    }
    string2[i] = '\0';
}

int main() {
    char palavra1[100];
    char palavra2[100];
    char maiorPalavra[100] = "";

    while(scanf("%s", palavra1) == 1 && scanf("%s", palavra2) == 1) {
        if(ContaLetraPalavra(palavra1) > ContaLetraPalavra(palavra2)) {
            printf("%s\n", palavra1);
            if(ContaLetraPalavra(palavra1) > ContaLetraPalavra(maiorPalavra)) {
                IgualaString1e2(palavra1, maiorPalavra);
            }
        }
        else if(ContaLetraPalavra(palavra1) < ContaLetraPalavra(palavra2)) {
            printf("%s\n", palavra2);
            if(ContaLetraPalavra(palavra2) > ContaLetraPalavra(maiorPalavra)) {
                IgualaString1e2(palavra2, maiorPalavra);
            }
        }
    }
    if(maiorPalavra[0] == 0) {
        printf("MAX:--");
    }
    else {
        printf("MAX:%s", maiorPalavra);
    }
    return 0;
}
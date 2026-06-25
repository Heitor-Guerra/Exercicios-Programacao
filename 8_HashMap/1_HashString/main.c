#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long toHash(char *str, int base) {
    long hash = 0;
    for(int i = strlen(str) - 1; i >= 0; i--) {
        hash += (int)*str * pow(base, i);
        str++;
    }
    return hash;
}

int main() {
    int base;
    int num;
    char string[32];

    scanf("%d %d", &base, &num);
    for(int i = 0; i < num; i++) {
        scanf("\n%s", string);
        long hash = toHash(string, base);
        printf("%ld\n", hash);
    }
    return 0;
}
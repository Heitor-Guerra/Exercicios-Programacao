#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long toHash(char *str, int base, int sizeHash) {
    unsigned long long hash = 0;
    for(int i = strlen(str) - 1; i >= 0; i--) {
        hash = (hash * base + (int)*str) % sizeHash;
        str++;
    }
    return hash;
}

int main() {
    int base;
    int num;
    int tamHash;

    char string[32];

    scanf("%d %d %d", &base, &num, &tamHash);
    for(int i = 0; i < num; i++) {
        scanf("\n%s", string);
        unsigned long long hash = toHash(string, base, tamHash);
        printf("%lld\n", hash);
    }
    return 0;
}
#include "string_utils.h"
#include <stdio.h>

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str) {
    int lenght = 0;
    while(*str) {
        lenght++;
        str++;
    }
    return lenght;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest) {
    while(*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str) {
    while(*str) {
        if(*str >= 'a' && *str <= 'z') {
            *str += 'A' - 'a';
        }
        str++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str) {
    while(*str) {
        if(*str >= 'A' && *str <= 'Z') {
            *str += 'a' - 'A';
        }
        str++;
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str) {
    char temp[string_length(str)];
    int j = 0;
    for(int i = string_length(str) - 1; i >= 0; i--) {
        temp[j] = str[i];
        j++;
    }
    
    for(int i = 0; i < string_length(str); i++) {
        str[i] = temp[i];
    }
}
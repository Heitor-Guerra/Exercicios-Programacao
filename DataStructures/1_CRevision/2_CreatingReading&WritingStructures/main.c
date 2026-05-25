#include "notasAluno.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    NotasAluno* aluno = leAluno();

    if(estaAprovadoAluno(aluno)) {
        printf("APROVADO");
    } else {
        printf("REPROVADO");
    }


    return 0;
}
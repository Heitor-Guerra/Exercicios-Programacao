#include "paciente.h"
#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100

int getIndicePaciente(int numPacientes, Paciente *pacientes, char *cartao) {
  for (int i = 0; i < numPacientes; i++) {
    char cartaoSusP[MAX_CARTAO_SUS];
    getCartaoSusPaciente(pacientes[i], cartaoSusP);
    if (strcmp(cartaoSusP, cartao) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  char choice;
  Paciente pacientes[MAX_PACIENTES];
  int numPacientes = 0, mediaIdades = 0, totalLesoes = 0, totalCirurgias = 0;

  const Data dataBase = criaData(12, 9, 2023);

  while (scanf("%c\n", &choice) && choice != 'F') {
    switch (choice) {
    case 'P':
      if (numPacientes >= MAX_PACIENTES) {
        puts("Maximo de pacientes no banco de dados alcaçado\nSAINDO!!");
        return 1;
      }
      pacientes[numPacientes] = lerPaciente();
      mediaIdades += calculaIdadePaciente(pacientes[numPacientes], dataBase);
      numPacientes++;
      break;
    case 'L': {
      Lesao lesao = lerLesao();
      char cartaoSUS[MAX_CARTAO_SUS];
      getCartaoSusLesao(lesao, cartaoSUS);
      int indexPaciente = getIndicePaciente(numPacientes, pacientes, cartaoSUS);
      if (indexPaciente != -1) {
        pacientes[indexPaciente] =
            vinculaLesaoPaciente(pacientes[indexPaciente], lesao);
      }
      break;
    }
    }
  }
  if (numPacientes) {
    mediaIdades /= numPacientes;
  }

  for (int i = 0; i < numPacientes; i++) {
    totalLesoes += getNumLesoesPaciente(pacientes[i]);
    totalCirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
  }

  printf("TOTAL PACIENTES: %d\n", numPacientes);
  printf("MEDIA IDADE (ANOS): ");
  if (mediaIdades != 0) {
    printf("%d\n", mediaIdades);
  } else {
    puts("-");
  }
  printf("TOTAL LESOES: %d\n", totalLesoes);
  printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
  puts("LISTA DE PACIENTES:");
  for (int i = 0; i < numPacientes; i++) {
    imprimePaciente(pacientes[i]);
  }

  return 0;
}

#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL_PAC_BANCO 2
#define TAM_INCREMENTO_PAC_BANCO 1

int main() {
  char escolha;
  int mediaIdade = 0, numTotalLesoes = 0, numTotalCir = 0;
  Data *dataBase = criaData(12, 9, 2023);

  int numPacAloc = TAM_INICIAL_PAC_BANCO, numPacUsado = 0;
  Paciente **bancoPac = (Paciente **)malloc(numPacAloc * sizeof(Paciente *));

  while (scanf("%c\n", &escolha) == 1 && escolha != 'F') {
    switch (escolha) {
    case 'P': {
      Paciente *p = lerPaciente();

      if (numPacUsado >= numPacAloc) {
        numPacAloc += TAM_INCREMENTO_PAC_BANCO;
        bancoPac =
            (Paciente **)realloc(bancoPac, numPacAloc * sizeof(Paciente *));
      }
      bancoPac[numPacUsado] = p;
      numPacUsado++;

      mediaIdade += calculaIdadePaciente(p, dataBase);

      break;
    }
    case 'L': {
      Lesao *l = lerLesao();
      int lesaoComPaciente = 0;

      for (int i = 0; i < numPacUsado; i++) {
        if (strcmp(getCartaoSusPaciente(bancoPac[i]), getCartaoSusLesao(l)) ==
            0) {
          adicionaLesaoPaciente(bancoPac[i], l);
          lesaoComPaciente = 1;

          numTotalLesoes++;
          if (verificaCirurgicaLesao(l)) {
            numTotalCir++;
          }
          break;
        }
      }
      if (!lesaoComPaciente) {
        liberaLesao(l);
      }

      break;
    }
    }
  }

  if (numPacUsado != 0) {
    mediaIdade /= numPacUsado;
  }

  printf("TOTAL PACIENTES: %d\n", numPacUsado);
  if (mediaIdade != 0) {
    printf("MEDIA IDADE (ANOS): %d\n", mediaIdade);
  } else {
    printf("MEDIA IDADE (ANOS): -\n");
  }
  printf("TOTAL LESOES: %d\n", numTotalLesoes);
  printf("TOTAL CIRURGIAS: %d\n", numTotalCir);
  printf("LISTA DE PACIENTES:\n");
  for (int i = 0; i < numPacUsado; i++) {
    imprimePaciente(bancoPac[i]);
  }

  for (int i = 0; i < numPacUsado; i++) {
    liberaPaciente(bancoPac[i]);
  }
  liberaData(dataBase);
  free(bancoPac);
  return 0;
}

#include "reserva.h"
#include <stdio.h>

void registraAreasComunsCondominio(int numAreas, Area *areas) {
  for (int i = 0; i < numAreas; i++) {
    areas[i] = lerArea();
  }
}

void registraMoradoresCondominio(int numMor, Morador *moradores) {
  for (int i = 0; i < numMor; i++) {
    moradores[i] = lerMorador();
  }
}

int procuraIndiceAreaCondominio(int numAreas, Area *areas, char *id) {
  for (int i = 0; i < numAreas; i++) {
    if (verificaIdArea(areas[i], id)) {
      return i;
    }
  }
  return -1;
}

int procuraIndiceCPFCondominio(int numMor, Morador *moradores, char *cpf) {
  for (int i = 0; i < numMor; i++) {
    if (verificaCPFMorador(moradores[i], cpf)) {
      return i;
    }
  }
  return -1;
}

int main() {
  int numAreas, numMoradores, solicitacoes, numReservas = 0;

  scanf("%d\n", &numAreas);
  Area areasComuns[numAreas];
  registraAreasComunsCondominio(numAreas, areasComuns);

  scanf("%d\n", &numMoradores);
  Morador moradores[numMoradores];
  registraMoradoresCondominio(numMoradores, moradores);

  scanf("%d\n", &solicitacoes);
  Reserva reservas[solicitacoes];
  for (int i = 0; i < solicitacoes; i++) {
    char id[MAX_TAM_ID], cpf[MAX_TAM_CPF];
    Data data;
    int qtdConvidados;

    scanf("%[^\n]\n", id);
    scanf("%[^\n]\n", cpf);
    data = lerData();
    scanf("%d\n", &qtdConvidados);

    Area areaRes;
    int areaIndex = procuraIndiceAreaCondominio(numAreas, areasComuns, id);
    if (areaIndex == -1) {
      continue;
    }
    areaRes = areasComuns[areaIndex];

    Morador moradorRes;
    int morIndex = procuraIndiceCPFCondominio(numMoradores, moradores, cpf);
    if (morIndex == -1) {
      continue;
    }
    moradorRes = moradores[morIndex];

    if (verificaSolicitacaoReserva(reservas, numReservas, moradorRes, areaRes,
                                   data, qtdConvidados)) {
      reservas[numReservas] =
          criaReserva(moradorRes, areaRes, data, qtdConvidados);
      numReservas++;
    }
  }

  for (int i = 0; i < numReservas; i++) {
    imprimeReserva(reservas[i]);
  }

  return 0;
}

#include "gerenciadorpacotes.h"
#include <stdlib.h>

struct gerenciadorpacotes {
  tPacote **pac;
  int numPac;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador *CriaGerenciador() {
  tGerenciador *gerenciador = (tGerenciador *)malloc(sizeof(tGerenciador));
  gerenciador->numPac = 0;
  gerenciador->pac = NULL;
  return gerenciador;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac) {
  geren->pac =
      (tPacote **)realloc(geren->pac, (geren->numPac + 1) * sizeof(tPacote *));
  geren->pac[geren->numPac] = pac;
  geren->numPac++;
}

/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador *geren) {
  for (int i = 0; i < geren->numPac; i++) {
    DestroiPacote(geren->pac[i]);
  }
  if (geren->pac != NULL) {
    free(geren->pac);
  }
  free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador *geren, int idx) {
  ImprimePacote(geren->pac[idx]);
}

/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador *geren) {
  for (int i = 0; i < geren->numPac; i++) {
    ImprimePacote(geren->pac[i]);
  }
}

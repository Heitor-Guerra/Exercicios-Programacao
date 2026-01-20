#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct pacote {
  Type tipo;
  void *dados;
  int numElem;
  int soma;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a
 * ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem) {
  tPacote *pacote = (tPacote *)malloc(sizeof(tPacote));
  pacote->tipo = type;
  pacote->numElem = numElem;
  pacote->soma = 0;
  switch (type) {
  case INT:
    pacote->dados = malloc(numElem * sizeof(int));
    break;
  case CHAR:
    pacote->dados = malloc(numElem * sizeof(char));
    break;
  }
  return pacote;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac) {
  free(pac->dados);
  free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac) {
  scanf("\n");
  for (int i = 0; i < pac->numElem; i++) {
    switch (pac->tipo) {
    case INT:
      scanf("%d", (int *)pac->dados + i);
      break;
    case CHAR:
      scanf("%c", (char *)pac->dados + i);
      break;
    }
  }
  scanf("\n");
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac) {
  CalculaSomaVerificacaoPacote(pac);
  printf("%d ", pac->soma);
  for (int i = 0; i < pac->numElem; i++) {
    switch (pac->tipo) {
    case INT:
      printf("%d ", ((int *)pac->dados)[i]);
      break;
    case CHAR:
      printf("%c", ((char *)pac->dados)[i]);
      break;
    }
  }
  printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac) {
  for (int i = 0; i < pac->numElem; i++) {
    switch (pac->tipo) {
    case INT:
      pac->soma += ((int *)pac->dados)[i];
      break;
    case CHAR:
      pac->soma += (int)((char *)pac->dados)[i];
      break;
    }
  }
}

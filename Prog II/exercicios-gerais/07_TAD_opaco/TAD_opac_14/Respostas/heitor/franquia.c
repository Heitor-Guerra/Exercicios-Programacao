#include "franquia.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONF 6

/**
 * @brief Estrutura que representa uma franquia.
 *
 * A estrutura franquia contém informações sobre o nome da franquia, sua
 * conferência e seu desempenho em casa e fora.
 *
 */
struct franquia {
  char nome[MAX_NOME];
  char conf[MAX_CONF];

  int vitoriaCasa, vitoriaFora;
  int derrotaCasa, derrotaFora;
};

#define MAX_NOME 32

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 *
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia() {
  tFranquia fran = (tFranquia)malloc(sizeof(struct franquia));
  if (!fran) {
    exit(1);
  }
  scanf("%s %s\n", fran->nome, fran->conf);
  fran->derrotaCasa = 0;
  fran->derrotaFora = 0;
  fran->vitoriaCasa = 0;
  fran->vitoriaFora = 0;

  return fran;
}

/**
 * @brief Libera a memória alocada para uma franquia.
 *
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f) { free(f); }

/**
 * @brief Imprime as informações de uma franquia.
 *
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f) {
  int derrotas = f->derrotaCasa + f->derrotaFora;
  int vitorias = f->vitoriaCasa + f->vitoriaFora;
  float aproveitamento = 0;
  if (vitorias + derrotas != 0) {
    aproveitamento = (float)vitorias / (vitorias + derrotas);
  }

  printf("%s [C%c] %d %d %.2f %d %d\n", f->nome, f->conf[0], vitorias, derrotas,
         aproveitamento * 100, f->vitoriaCasa, f->vitoriaFora);
}

/**
 * @brief Retorna o nome da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char *GetNomeFranquia(tFranquia f) { return f->nome; }

/**
 * @brief Retorna a conferência da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char *GetConferenciaFranquia(tFranquia f) { return f->conf; }

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f) { f->vitoriaCasa++; }

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f) { f->vitoriaFora++; }

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f) { f->derrotaCasa++; }

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f) { f->derrotaFora++; }

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f) { return f->vitoriaCasa; }

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f) { return f->vitoriaFora; }

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f) { return f->derrotaCasa; }

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f) { return f->derrotaFora; }

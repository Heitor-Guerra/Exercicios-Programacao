#include <math.h>
#include <stdio.h>

#define DIMENSOES 2

typedef struct {
  float coordenadas[DIMENSOES];
  float hitbox;
} tAlvo;

typedef struct {
  float coordenadas[DIMENSOES];
  float hitbox;
} tTiro;

tAlvo inicializaAlvo(tAlvo alvo) {
  int i;
  for (i = 0; i < DIMENSOES; i++) {
    scanf("%f", &alvo.coordenadas[i]);
  }
  scanf("%f", &alvo.hitbox);
  return alvo;
}

tTiro inicializaTiro(tTiro tiro) {
  int i;
  for (i = 0; i < DIMENSOES; i++) {
    scanf("%f", &tiro.coordenadas[i]);
  }
  scanf("%f", &tiro.hitbox);
  return tiro;
}

float calculaDistancia(tAlvo alvo, tTiro tiro) {
  float distancia = 0;
  int i;
  for (i = 0; i < DIMENSOES; i++) {
    distancia += pow(alvo.coordenadas[i] - tiro.coordenadas[i], 2);
  }
  distancia = sqrt(distancia);
  return distancia;
}

int acertouTiro(tAlvo alvo, tTiro tiro) {
  if (calculaDistancia(alvo, tiro) <= (alvo.hitbox + tiro.hitbox)) {
    return 1;
  }
  return 0;
}

int main() {
  tAlvo alvo;
  tTiro tiro;
  alvo = inicializaAlvo(alvo);
  tiro = inicializaTiro(tiro);

  if (acertouTiro(alvo, tiro)) {
    printf("ACERTOU");
  } else {
    printf("ERROU");
  }

  return 0;
}

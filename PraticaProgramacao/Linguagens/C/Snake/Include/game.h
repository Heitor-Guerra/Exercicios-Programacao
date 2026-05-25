#ifndef _GAME_H
#define _GAME_H

#include "macros.h"
#include "snake.h"

struct game_t {
  short int map[DIMENSIONS][DIMENSIONS];
  struct snake_t snake;
  short int fruit[NUM_DIMENSIONS][1];
  int points;
};

int getPointsGame(struct game_t *game);

struct game_t initializeGame();

bool checkColisionGame(struct game_t *game);

void genFruitGame(struct game_t *game);

int makeMovementGame(struct game_t *game);

void printMapGame(struct game_t *game);

void playGame(struct game_t *game);

#endif

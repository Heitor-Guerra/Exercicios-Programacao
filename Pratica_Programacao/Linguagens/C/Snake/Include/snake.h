#ifndef _SNAKE_H
#define _SNAKE_H

#include "macros.h"

struct snake_t {
  short int head[NUM_DIMENSIONS][1];
  short length;
};

struct snake_t initializeSnake();

short int getXHeadSnake(struct snake_t *snake);

short int getYHeadSnake(struct snake_t *snake);

short int getLengthSnake(struct snake_t *snake);

void increaseLengthSnake(struct snake_t *snake);

int moveSnake(struct snake_t *snake, char command);

#endif

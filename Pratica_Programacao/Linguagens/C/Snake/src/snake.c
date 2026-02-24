#include "../Include/snake.h"

struct snake_t initializeSnake() {
  struct snake_t snake;
  snake.head[X_POSITION][0] = DIMENSIONS / 2;
  snake.head[Y_POSITION][0] = DIMENSIONS / 2;
  snake.length = 1;
  return snake;
}

short int getXHeadSnake(struct snake_t *snake) {
  return snake->head[X_POSITION][0];
}

short int getYHeadSnake(struct snake_t *snake) {
  return snake->head[Y_POSITION][0];
}

short int getLengthSnake(struct snake_t *snake) { return snake->length; }

void increaseLengthSnake(struct snake_t *snake) { snake->length++; }

int moveSnake(struct snake_t *snake, char command) {
  switch (command) {
  case 'w':
    snake->head[Y_POSITION][0]--;
    break;
  case 's':
    snake->head[Y_POSITION][0]++;
    break;
  case 'a':
    snake->head[X_POSITION][0]--;
    break;
  case 'd':
    snake->head[X_POSITION][0]++;
    break;
  }
  if (snake->head[Y_POSITION][0] < 0 ||
      snake->head[Y_POSITION][0] >= DIMENSIONS ||
      snake->head[X_POSITION][0] < 0 ||
      snake->head[X_POSITION][0] >= DIMENSIONS) {
    return 0;
  }
  return 1;
}

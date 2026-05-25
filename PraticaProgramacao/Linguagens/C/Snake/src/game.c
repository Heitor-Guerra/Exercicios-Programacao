#include "../Include/game.h"

int getPointsGame(struct game_t *game) { return game->points; }

struct game_t initializeGame() {
  struct game_t game;
  for (int i = 0; i < DIMENSIONS; i++) {
    for (int j = 0; j < DIMENSIONS; j++) {
      game.map[i][j] = 0;
    }
  }
  game.snake = initializeSnake();
  genFruitGame(&game);
  game.points = 0;
  return game;
}

bool checkColisionGame(struct game_t *game) {
  return game->map[getYHeadSnake(&(game->snake))]
                  [getXHeadSnake(&(game->snake))] != 0;
}

void genFruitGame(struct game_t *game) {
  int x;
  int y;
  do {
    x = rand() % DIMENSIONS;
    y = rand() % DIMENSIONS;
  } while (game->map[y][x] != 0);
  game->fruit[X_POSITION][0] = x;
  game->fruit[Y_POSITION][0] = y;
}

int makeMovementGame(struct game_t *game) {
  for (int i = 0; i < DIMENSIONS; i++) {
    for (int j = 0; j < DIMENSIONS; j++) {
      if (game->map[i][j] != 0) {
        game->map[i][j]++;
        game->map[i][j] %= (getLengthSnake(&(game->snake)) + 1);
      }
    }
  }
  game->map[getYHeadSnake(&(game->snake))][getXHeadSnake(&(game->snake))]++;

  char move = 0;

  while (move != 'w' && move != 's' && move != 'a' && move != 'd') {
    scanf("%c", &move);
    scanf("%*[^\n]");
    scanf("%*c");
  }

  if (!moveSnake(&(game->snake), move)) {
    return 0;
  }
  if (getYHeadSnake(&(game->snake)) == game->fruit[Y_POSITION][0] &&
      getXHeadSnake(&(game->snake)) == game->fruit[X_POSITION][0]) {
    genFruitGame(game);
    increaseLengthSnake(&(game->snake));
    game->points++;
  }
  return 1;
}

void printMapGame(struct game_t *game) {
  system("clear");
  printf("Points: %d\n", game->points);
  puts("- - - - - - - - - - - -");
  for (int i = 0; i < DIMENSIONS; i++) {
    printf("| ");
    for (int j = 0; j < DIMENSIONS; j++) {
      if (i == getYHeadSnake(&(game->snake)) &&
          j == getXHeadSnake(&(game->snake))) {
        printf("8 ");
      } else if (i == game->fruit[Y_POSITION][0] &&
                 j == game->fruit[X_POSITION][0]) {
        printf("0 ");
      } else if (game->map[i][j] != 0) {
        printf("# ");
      } else {
        printf("  ");
      }
    }
    printf("|\n");
  }
  puts("- - - - - - - - - - - -");
}

void playGame(struct game_t *game) {
  while (1) {
    printMapGame(game);
    if (!makeMovementGame(game) || checkColisionGame(game)) {
      system("clear");
      printf("GAME OVER!!!\n");
      return;
    }
  }
}

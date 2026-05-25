#include "../Include/game.h"
#include <time.h>

void record(int points) {
  char recordGame;
  do {
    puts("Do you want to record your score? [y/n]");
    scanf("%c", &recordGame);
    scanf("%*[^\n]");
    scanf("%*c");
  } while (recordGame != 'y' && recordGame != 'n');
  if (recordGame == 'y') {
    FILE *recordsFile;
    if (!(recordsFile = fopen("Records/Records.txt", "a"))) {
      puts("ERROR: Couldn't access the records file");
      exit(1);
    }
    time_t t = time(NULL);
    struct tm *time = localtime(&t);
    fprintf(recordsFile, "Points: %d --- Date: %s\n", points, asctime(time));
  }
}

int main() {
  struct game_t game;
  char continueGame;

  do {
    game = initializeGame();

    playGame(&game);

    record(getPointsGame(&game));

    do {
      puts("Do you want to continue playing? [y/n]");
      scanf("%c", &continueGame);
      scanf("%*[^\n]");
      scanf("%*c");
    } while (continueGame != 'y' && continueGame != 'n');
  } while (continueGame == 'y');

  return 0;
}

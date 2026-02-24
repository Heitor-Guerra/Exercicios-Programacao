typedef enum {
  ONES,
  TWOS,
  THREES,
  FOURS,
  FIVES,
  SIXES,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  LITTLE_STRAIGHT,
  BIG_STRAIGHT,
  CHOICE,
  YACHT
} category_t;

typedef struct {
  int faces[5];
} dice_t;

int score(dice_t dice, category_t category) {
  int nums[7] = {0};
  for (int i = 0; i < 5; i++) {
    nums[dice.faces[i]]++;
  }
  switch (category) {
  case ONES:
    return nums[1];
  case TWOS:
    return nums[2] * 2;
  case THREES:
    return nums[3] * 3;
  case FOURS:
    return nums[4] * 4;
  case FIVES:
    return nums[5] * 5;
  case SIXES:
    return nums[6] * 6;
  case FULL_HOUSE: {
    int sum = 0;
    for (int i = 1; i < 7; i++) {
      if (nums[i] > 0 && nums[i] != 2 && nums[i] != 3) {
        return 0;
      }
      sum += i * nums[i];
    }
    return sum;
  }
  case FOUR_OF_A_KIND:
    for (int i = 1; i < 7; i++) {
      if (nums[i] >= 4) {
        return i * 4;
      }
    }
    return 0;
  case LITTLE_STRAIGHT:
    for (int i = 1; i < 6; i++) {
      if (nums[i] != 1) {
        return 0;
      }
    }
    return 30;
  case BIG_STRAIGHT:
    for (int i = 2; i < 7; i++) {
      if (nums[i] != 1) {
        return 0;
      }
    }
    return 30;
  case CHOICE: {
    int sum = 0;
    for (int i = 1; i < 7; i++) {
      sum += i * nums[i];
    }
    return sum;
  }
  case YACHT:
    for (int i = 1; i < 7; i++) {
      if (nums[i] == 5) {
        return 50;
      }
    }
    return 0;
  }
  return 0;
}

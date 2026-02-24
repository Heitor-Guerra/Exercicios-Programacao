#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DIGITS_ARRAY_SIZE 64

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base,
              size_t input_length) {
  if (input_base < 2 || output_base < 2 || input_length < 1) {
    return 0;
  }

  // Convert from input_base to decimal
  int decimalNumber = 0;
  for (size_t i = 0; i < input_length; i++) {
    if (digits[i] >= input_base || digits[i] < 0) {
      return 0;
    }
    decimalNumber += digits[i] * pow(input_base, input_length - i - 1);
  }

  // Convert from decimal to outputBase
  size_t length = 0;
  do {
    // Move all digits by 1 and put the new value at the start
    for (int i = length - 1; i >= 0; i--) {
      digits[i + 1] = digits[i];
    }
    digits[0] = decimalNumber % output_base;
    decimalNumber /= output_base;
    length++;
  } while (decimalNumber > 0);
  return length;
}

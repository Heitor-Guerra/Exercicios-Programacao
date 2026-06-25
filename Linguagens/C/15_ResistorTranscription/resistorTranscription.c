
#include <math.h>

typedef enum {
  BLACK = 0,
  BROWN = 1,
  RED = 2,
  ORANGE = 3,
  YELLOW = 4,
  GREEN = 5,
  BLUE = 6,
  VIOLET = 7,
  GREY = 8,
  WHITE = 9,
} resistor_band_t;

typedef enum {
  OHMS,
  KILOOHMS,
  MEGAOHMS,
  GIGAOHMS,
  TERAOHMS,
  PETAOHMS,
} resistor_unit_t;

typedef struct {
  unsigned short int value;
  resistor_unit_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t color[]) {
  resistor_value_t band;
  band.value = (color[0] * 10 + color[1]) * pow(10, color[2] % 3);
  band.unit = color[2] / 3;
  if (band.value > 1000) {
    band.value /= 1000;
    band.unit++;
  }
  return band;
}

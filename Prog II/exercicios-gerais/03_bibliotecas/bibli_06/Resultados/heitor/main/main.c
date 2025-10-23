#include "temperature_conversor.h"
#include <stdio.h>

void printConverted(float temp, char u1, char u2) {
  switch (u1) {
  case 'c':
    if (u2 == 'f') {
      printf("%.2fFº",
             convert_temperature(temp, convert_celsius_to_fahrenheit));
      return;
    } else if (u2 == 'k') {
      printf("%.2fK", convert_temperature(temp, convert_celsius_to_kelvin));
      return;
    }
  case 'f':
    if (u2 == 'c') {
      printf("%.2fCº",
             convert_temperature(temp, convert_fahrenheit_to_celsius));
      return;
    } else if (u2 == 'k') {
      printf("%.2fK", convert_temperature(temp, convert_fahrenheit_to_kelvin));
      return;
    }
  case 'k':
    if (u2 == 'c') {
      printf("%.2fCº", convert_temperature(temp, convert_kelvin_to_celsius));
      return;
    } else if (u2 == 'f') {
      printf("%.2fFº", convert_temperature(temp, convert_kelvin_to_fahrenheit));
      return;
    }
  }
}

int main() {
  float temperature;
  char unity1, unity2;
  scanf("%f %c %c", &temperature, &unity1, &unity2);

  printf("Temperature: ");
  printConverted(temperature, unity1, unity2);

  return 0;
}

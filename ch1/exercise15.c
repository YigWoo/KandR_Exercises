/*
 * A temperature conversion program
 * Output: some plain table of temperature conversion
 * Compilation: gcc exercise15.c
 * Execution: ./a.out
 *
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  int fahr, celsius;
  int lower, upper, step;
  int temperConversion(int);

  lower = 0;
  upper = 300;
  step = 20;

  for (fahr = lower; fahr <= upper; fahr += step) {
    celsius = temperConversion(fahr);
    printf("%d\t%d\n", fahr, celsius);
  }
}

int temperConversion(int fahr) {
  int celsius;
  celsius = 5 * (fahr - 32) / 9;
  return celsius;
}

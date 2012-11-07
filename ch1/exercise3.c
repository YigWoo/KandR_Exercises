/*
 * A temperature conversion program with a heading above the table
 * No input, output is the preset convesion data, print F-C table from fahr = 0, 20, ..., 300.
 * 
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  float fahrT, celsiusT;
  int lower, upper, step;

  /* set the lower and upper limit, and the step value */
  lower = 0;
  upper = 300;
  step = 20;

  /* add a heading above the table */
  printf("\tFahrenheit\tCelsius\n");
  /* Step through lower to upper to get the table */
  for (fahrT=lower; fahrT<=upper; fahrT+=step) {
    celsiusT = (5.0 / 9.0) * (fahrT - 32.0);
    printf("\t%3.0f\t\t%6.1f\n", fahrT, celsiusT);
  }
}


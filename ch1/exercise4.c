/*
 * A program that print the C-F temperature conversion table.
 * No input, output is a table that lists the C-F temperature conversion results from 0 to 300 celsius temperature.
 *
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  float fahrT, celsiusT;
  int lower, upper, step;

  /* set the lower and upper limits, set the step size */
  lower = 0;
  upper = 300;
  step = 20;
  
  /* initialize fahrT and celsiusT */
  fahrT = celsiusT = 0;

  /* print the heading of the table */
  printf("\tCelcius\tFahrenheit\n");
  for (celsiusT = lower; celsiusT <= upper; celsiusT += step) {
    fahrT = celsiusT * 9.0 / 5.0 + 32.0;
    printf("\t%3.0f\t%6.1f\n", celsiusT, fahrT);
  }
}


/*
 * A program to count blanks, tabs and newlines.
 * Compilation: gcc exercise8.c
 * Execution: ./a.out
 * Input: keyboard input
 * Output: the respective sum of blanks, tabs and newlines input by user.
 *
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  /* initialize the sum of blanks, tabs and newlines to 0 */
  int blankSum, tabSum, newlineSum;
  int tmpChar;

  blankSum = tabSum = newlineSum = 0;
  /* while user does not input EOF (C-d) to indicate the end of the input */
  /*   take in a character input */
  while ( (tmpChar = getchar()) != EOF ) {
  /*   if the character is one character among blank, tab or newline */
  /*     increment the sum of respective sign */
    if (tmpChar == ' ')
      blankSum++;
    if (tmpChar == '\t')
      tabSum++;
    if (tmpChar == '\n')
      newlineSum++;
  /*   else, do nothing */
  }
  /* output the result of the summation */
  printf("The sum of blanks, tabs and newlines: %d, %d, %d\n", blankSum, tabSum, newlineSum);
}

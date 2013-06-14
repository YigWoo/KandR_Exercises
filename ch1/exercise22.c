/*
 * A program to fold long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th
 * column of input. The program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
 * Compilation: gcc exercise22.c
 * Execution: ./a.out < text
 * Author: Yigwoo
 */

#define N 80
#include <stdio.h>

main() {
  /* get one line */
  /* parse the line a character a time */
  /* keep the count of the character */
  /* use a flag to indicate whether the current position is in blanks */
  /* while count does not reach N */
  /*   if the character is a blank or tab */
  /*     set the flag to true */
  /*     record the blank or tab in one string */
  /*   if the character is not a blank or tab */
  /*     if the flag is true */
  /*       set the flag to false */
  /*       paste the blank string into output string */
  /*       record the character to output string */
  /*     if the flag is false */
  /*       record the character to output string */
  /* when the count reaches N */
  /*   if the Nth character is a blank or tab */
  /*     discard it */
  /*   if the Nth character is not a blank */
  /*     keep it and paste the blank string into output string */
  /* start another line and keep on parsing the input line */
}

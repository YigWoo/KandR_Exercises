/*
 * A program to prints its input one word per line
 * Compilation: gcc exercise11.c
 * Execution: ./a.out < test12
 * Input: plain text | standard input
 * Output: the text of the input, one word per line, ignoring space, tabs
 * 
 * Author: Yigwoo
 */

#define IN 1			/* Inside a space */
#define OUT 0			/* Outside a space */
#include <stdio.h>

main() {
  /* the status is: outside a space */
  int inSpace;
  int c;
  /* while the input is not EOF */
  /* read in one cacter */
  inSpace = IN;
  while ((c = getchar()) != EOF) {
  /*   if the cacter is space, tab, or newline */
    if (c == ' ' | c == '\t' | c == '\n') {
  /*     if the status is outside a space */
      if (inSpace == OUT) {
  /*       print a newline */
  /*       set the status to inside a space */
	putchar('\n');
	inSpace = IN;

      }
    }
    else {
  /*     set the status to outside a space */
  /*     print the cacter */
      inSpace = OUT;
      putchar(c);
    }
  }
}


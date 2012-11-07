/*
 * A program to copy its input to output while replace multiple blanks with a single blank
 * Input: plain text
 * Output: the originally text with multiple blanks merged into single blank
 * 
 * Compilation: gcc exercise9.c
 * Execution: ./a.out < test9
 *
 * Author: Yigwoo
 */
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <string.h>

main() {
  int mergeMultipleBlanks();
  /* to copy the input to the output, we need an empty string (This is my original idea) */ 
  /* or we can just leave this behind, output the incoming character immediately when we know it is not blank */

  int tmpChar;
  int isEOF;
  /* read in one character */
  /* while the character is not EOF (C-d) */
  while ((tmpChar = getchar()) != EOF) {
  /* if the character is not space */
    if (tmpChar != ' ')
  /*   print the character */
      printf("%c", tmpChar);
  /* if the character is space */
    else {
  /*   calls Routine 1 */
      isEOF = mergeMultipleBlanks();
  /*   if Routine 1 returns 0, continue to read new character */
  /*   if Routine 1 returns 1, that is, an EOF is detected, break the loop */
      if (isEOF == TRUE)
	break;
    }
  }
}
  /* (Routine 1) */
int mergeMultipleBlanks() {
  int tmpChar;
  /*   read in a new character */
  tmpChar = getchar();
  /*   if the new character is EOF (C-d) */
  if (tmpChar == EOF) {
  /*     output a blank, and return 1 to indicate EOF detected */
    printf(" ");
    return TRUE;
  }
  /*   if the new character is not blank nor EOF */
  if (tmpChar != ' ') {
  /*     output a blank, and output the new character and return 0*/
    printf(" %c", tmpChar);
    return FALSE;
  }
  /*   if the new character is blank */
  /*     recall Routine 1 */
  return mergeMultipleBlanks();
}


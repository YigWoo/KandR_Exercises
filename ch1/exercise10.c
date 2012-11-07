/*
 * A program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash with \\. This makes tabs and backspaces visible in an unambiguous way.
 * Compilation: gcc exercise10.c
 * Execution: ./a.out
 * Input: plain text or standard input
 * Output: plain text with tab, backspace and backslach replaced with \t, \b and \\
 *
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  int tmpChar;
  
  while ((tmpChar = getchar()) != EOF) {
    if (tmpChar == '\t') {
      printf("\\t");
      continue;
    }
    if (tmpChar == '\b') {
      printf("\\b");
      continue;
    }
    if (tmpChar == '\\') {
      printf("\\\\");
      continue;
    }
    printf("%d", tmpChar);
  }
}

/*
 * A program to print the value of EOF.
 *
 * Compilation: gcc exercise7.c
 * Execution: ./a.out
 * Input: EOF (C-d)
 * Output: the printable value of EOF
 *
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  int c;
  
  c = getchar();
  printf("%%c option: %c\n", c);
  printf("%%d option: %c\n", c);
}


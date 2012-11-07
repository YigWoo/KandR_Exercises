/*
 * A program to verify that the expression getchar() != EOF is 0 or 1.
 * Compilation: gcc exercise6.c
 * Execution: ./a.out
 * Input: any character you can input, for example, 'a', 'b', or EOF (C-d), for EOF.
 * Output: it prints 0, for others it prints 1.
 * 
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  int c;
  
  printf("%d\n", getchar() != EOF);
}


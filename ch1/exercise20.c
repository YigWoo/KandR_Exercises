/*
 * A program that replaces tabs in the input with the proper number of blanks to  space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns. 
 * Compilation: gcc exercise20.c
 * Execution: ./a.out < test20
 * Author: Yigwoo
 */
#define TABSTOP 4
#define MAXLINE 1000
#include <stdio.h>

main() {
  char s[MAXLINE];
  char c[4*MAXLINE];
  int length;
  int i, j;

  while ((length = getLine(s, MAXLINE)) > 0) {
    i = j = 0;
    while(i < length) {
      if (s[i] == '\t') {
	int k;
	for (k = 0; k < 4; k++)
	  c[j++] = ' ';
	i++;
      }
      else
	c[j++] = s[i++];
    }
    printf("%s", c);
  }
}


int getLine(char s[], int lim) {
  int c, i;
  
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


/*
 * A program that prints all its input lines that are longer than 80 characters
 * Input: plain text or standard input
 * Output: input lines that are longer 80
 *
 * Author: Yigwoo
 */

#include <stdio.h>
#define MAXLINE 1000

//int getline(char s[], int lim);
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

main() {
  char line[MAXLINE];
  int len;

  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len >= 80)
      printf("%s", line);
  }
}

/*
 * this is a program that reverses its input a line at a time
 * Compilation: gcc exercise19.c
 * Execution: ./a.out < test19
 * Input: plain text or text files
 * Output: input text reversed a line at a time
 * Author: Yigwoo
 */

/*
 * the reverse() function could be used to solve swap text problem using flip hands solution.
 * see it on "Programming Perl" 2nd Edition chapter 2.3 "The Power of Primitives"
 */
#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[], int start, int end);

main() {
  char s[MAXLINE];
  int length;

  while ((length = getLine(s, MAXLINE)) > 0) {
    reverse(s, 0, length - 2);
    printf("%s", s);
  }

}

void reverse(char s[], int start, int end) {
  /*
   * reverse a character line
   */
  int i, j;
  char tmpChar;
  
  for (i = start; i <= ((end - start) / 2); i++) {
    j = end - i;
    if (j != i) {
      tmpChar = s[i];
      s[i] = s[j];
      s[j] = tmpChar;
    }    
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


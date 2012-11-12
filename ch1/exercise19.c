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

void reverse(char s[], start, int end);

main() {

}

void reverse(char s[], int start, int end) {

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

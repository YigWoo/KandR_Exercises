/*
 * A program that will print the longest line of the input, the longest line could be arbitrarily long.
 *
 * Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length
 * of arbitrarily long input lines, and as much as possible of the text.
 * :Since, the statement require me to only modify the main routine of the longest-line program, it means
 * I cannot use malloc() and free() from stdlib.h, so I should figure out another way to address this problem
 *
 * Input: plain text or standard input
 * Output: the longest line of the input
 *
 * Author: Yigwoo
 */

#include <stdio.h>

main() {
  /* if malloc() and free() are to be used, the following procedure could be used 
   *  set the maximum line of the input to a small digit, like 0
   *  get a line from the input till meets the end of the file
   *  if the line length is longer than the maximum line
   *    record the current line, and modify the maximum number
   *  print the maximum line
   */
  
  /* another way to address the problem */
  
}

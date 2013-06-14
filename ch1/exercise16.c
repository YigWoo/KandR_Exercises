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
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[], int lim);
void copy(char to[], char from[]);

main() {
  /* if malloc() and free() are to be used, the following procedure could be used 
   *  set the maximum line of the input to a small digit, like 0
   *  get a line from the input till meets the end of the file
   *  if the line length is longer than the maximum line
   *    record the current line, and modify the maximum number
   *  print the maximum line
   */
  
  /* another way to address the problem */
  /* the examp give the getLine method and copy method */
  /* and the requirement is that we should modify the main routine the accomplish the task */
  /* the end of a line is indicated by a newline symbol */
  /* so the thing to do is to after read a character sequence using getLine() */
  /* is to check the last symbol of the sequence is newline or not */

  int hasMore;
  int maxLen;
  int tempLen;
  int lineLen;

  char line[MAXLINE];
  char longest[MAXLINE];

  /* use a marker to tell whether the current line has more to offer */
  /* set the marker to true when the line has more characters, set it to false otherwise */
  /* the initial state of the marker should be false */
  maxLen = 0;
  tempLen = 0;
  lineLen = 0;
  hasMore = FALSE;
  /* while the cursor doesn't reach the end of the file */
  /*   get a new line sequence */
  /*   if the last symbol of the sequence is not a newline character */
  /*     if the marker is true */
  /*       accumulate the length of the current line */
  /*     if the marker is false */
  /*       copy the current line */
  /*       accumulate the length of the current line */
  /*     if the length of the line is larger than the largest length */
  /*       copy the line into the largest one  */
  /*     set the marker to true */
  /*   if the last symbol of the sequence is a newline character */
  /*     if the marker is true, means this is the last sequence of a line */
  /*       accumulate the length of the line */
  /*     if the marker is false, means this is a line within the maximum capacity of the getLine function */
  /*       record the length of the current line */
  /*     compare the length of the current line(whether full or not full) to the largest length */
  /*     if the length of the line is larger */
  /*       modify the largest line length with the length of the current line */
  /*       if the marker is false */
  /*         copy the sequence into the largest line string */
  /*     set the marker to false */
  /*     set the temporary line length to zero */

  while ((tempLen = getLine(line, MAXLINE)) > 0) {
    if (line[tempLen - 1] != '\n') {
      if (hasMore == TRUE)
	lineLen += tempLen;
      else {
	lineLen = tempLen;
      }
      if (lineLen > maxLen)
	copy(longest, line);
      hasMore = TRUE;
    }
    else {
      if (hasMore == TRUE) 
	lineLen += tempLen;
      else
	lineLen = tempLen;
      if ( lineLen > maxLen) {
	maxLen = lineLen;
	if (hasMore == FALSE)
	  copy(longest, line);
      }
      hasMore == FALSE;
      lineLen = 0;
    }
  }

  if (maxLen > 0) {
    printf("The longest line's length is %d.\n", maxLen);
    printf("%s\n", longest);
  }
  return 0;
}

/* getLine: read a line into s, return length */
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}


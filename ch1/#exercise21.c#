/*
 * A program that replaces strings of blanks by the minimum number of tabs and blanks to achieve the 
 * same spacing.
 * Compilation: gcc exercise21.c
 * Execution: ./a.out < testfile
 * Author: Yigwoo
 */
#define TABSTOP 4
#define MAXLINE 1000
#define TRUE 1
#define FALSE 0
#include <stdio.h>

main() {
  int getLine(char *, int);
  int inblank;
  int length;
  int blankCount;
  char s[MAXLINE];
  char c[MAXLINE];
  int i, j, k;
  /* read one line */
  while ((length = getLine(s, MAXLINE)) > 0) {
    i = j = 0;
    blankCount = 0;
    inblank = FALSE;
  /* parse the line, we use a flag to indicate whether we've met blanks before */
    while (i < length) {
  /* if the current character is not a blank */
  /*   if the flag is true */
  /*     if the blank count is four */
  /*       entab the blanks */
  /*     if the blank count is not four, restore the blanks */
  /*   copy the character as it is */
      if (s[i] != ' ') {
	if (inblank == TRUE) {
	  if (blankCount == 4) 
	    c[j++] = '\t';
	  else {
	    for (k = 0; k < blankCount; k++) {
	      c[j++] = ' ';
	    }
	  }
	  blankCount = 0;
	}
	c[j++] = s[i++];
      }
  /* if the current character is a blank */
  /*   if the flag is false */
  /*     set the flag to true */
  /*     increment the blank count */
  /*   if the flag is true */
  /*     increment the blank count */
  /*     if the blank count is four */
  /*       entab the blanks */
      else {
      	if (inblank == FALSE) {
      	  inblank = TRUE;
      	  blankCount =1;
      	}
      	else {
      	  if (blankCount == 4) {
      	    c[j++] = '\t';
      	    blankCount = 1;
      	  }
      	  else {
      	    blankCount++;
      	  }
      	}
      	i++;
      }
    }	  
  /* repeat the routine until meet the end of the file */
    c[j] = 0;
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

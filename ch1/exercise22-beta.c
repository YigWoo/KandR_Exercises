/*
 * A program to fold long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th
 * column of input. The program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
 * Compilation: gcc exercise22-beta.c public-method.c
 * Execution: ./a.out < text
 * Author: This is a method from Rick Dearman.
 * Comment: The method won't work if there does not exist a blank or tab
 * in every N characters. It can be fixed with an extra array or just output the characters right away.
 */

#define N 80
#define MAXLINE 1000
#include <stdio.h>
#include "public-method.h"

main () {
  /* get a input line */
  /* if the line is shorter than N */
  /*   do nothing */
  /* else parse the line */
  /*   keep track of the last blank or tab */
  /*   keep track of the current position */
  /*   if the current position reaches N */
  /*     replace the last blank with a newline */
  /* print the line */

  char s[MAXLINE];
  int t;
  int location;
  int len;
  int spaceholder;
  
  while ((len = getLine(s, MAXLINE)) > 0) { 
    if (len < N) {}
    else {
      t = 0;
      location = 0;
      spaceholder = -1;
      
      while (t < len) {
  	if (s[t] == ' ' || s[t] == '\t')
  	  spaceholder = t;
	
  	if (location == N) {
	  if (spaceholder != -1) {
	    s[spaceholder] = '\n';
	    location = 0;
	    spaceholder = -1;
	  }
  	}
	
  	t++;
  	location++;
      }
    }
    printf("%s", s);
  }
}


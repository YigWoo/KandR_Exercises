/* 
 * This is a program that removes trailing blanks and tabs from each line of input, and delete entirely blank lines.
 * Compilation: gcc exercise18.c
 * Execution: ./a.out < test18
 * Input: plain text or text file
 * Out: text with trailing blanks, tabs and blank lines removed
 * Author: Yigwoo
 *
 */
#define MAXLINE 1000
#include <stdio.h>

int getLine(char s[], int lim);

main() {
  /* get a line */
  /* starting from the back of the line, delete tabs and blanks until encounters other characters */
  /* after the process, if the line is only left with a newline, delete the newline too */
  char line[MAXLINE];
  char printLine[MAXLINE];
  int len;
  int i;
  int newline;

  while ((len = getLine(line, MAXLINE)) > 0) {
    newline = (line[len-1] == '\n') ? 1 : 0;
    i = len - newline - 1;
    while(line[i] == ' ' || line[i] == '\t') {
      len--;
      i--;
    }
    
    //    printf("%d-", len);
    if(len > 1) {
      for(i = 0; i < len -1; i++)
    	printLine[i] = line[i];
      if(newline)
    	printLine[i++] = '\n';
      printLine[i] = '\0';
      printf("%s", printLine);
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

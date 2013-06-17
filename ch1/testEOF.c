#include <stdio.h>

main() {
  int c;
  while ((c = getchar()) != EOF) {
    if(c == ' ' | c == '\t' | c == '\n')
      continue;
    else
      putchar(c);
  }

}
       

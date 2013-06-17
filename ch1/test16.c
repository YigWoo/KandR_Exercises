#include <stdio.h>
#include <fcntl.h>
#define SHORT 20
#define MIDIUM 100
#define LONG 1000
#define ULTRALONG 10000

main() {
  int i;
  char buf[ULTRALONG * 2];
  int filedes;
  
  filedes = open("./test16", O_WRONLY|O_CREAT);
  for (i = 0; i < ULTRALONG; i++)
    buf[i] = 'a';
  write(filedes, buf, ULTRALONG);
  write(filedes, "\n", 1);
  for (i = 0; i < LONG; i++)
    buf[i] = 'b';
  write(filedes, buf, LONG);
  write(filedes, "\n", 1);
  for (i = 0; i < MIDIUM; i++)
    buf[i] = 'c';
  write(filedes, buf, MIDIUM);
  write(filedes, "\n", 1);
  for (i = 0; i < SHORT; i++)
    buf[i] = 'd';
  write(filedes, buf, SHORT);
  write(filedes, "\n", 1);
  for (i = 0; i < ULTRALONG * 2; i++)
    buf[i] = 'f';
  write(filedes, buf, ULTRALONG * 2);
  write(filedes, "\n", 1);
  return 0;
}

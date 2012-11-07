#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters!\n");
	else
		buf[bufp++] = c;
}

int getint(int *pn)
{
	int c, sign;

	while(isspace(c = getch())) /*skip whitespaces*/
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		//ungetch(c);		/* not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
	{
		ungetch(c);
	}
	return c;
}

int main()
{
	int i;
	int status;
	status = getint(&i);
	if (status != 0)
		printf("%d\n", i);
	else
		printf("Not a number\n");
}


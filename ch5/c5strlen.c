#include <stdio.h>

int strlen(const char *s)
{
	const char *p = s;
	while(*p != '\0')
		p++;
	return p-s;
}

int main(int argc, char const *argv[])
{
	char * s = "This is a test message!!!";
	int a = strlen(s);
	printf("%d\n", a);
	return 0;
}
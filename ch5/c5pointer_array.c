#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 	1000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];	//Pointer arrays to hold character arrays

char * alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)	//'\n' as delimiter, check for EOF condition
		s[i] = c;
	if (c == '\n')	//if the line ended fine with a '\n', put the '\n' character back
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';	//end of the string
	return i;		//return the length of the line
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;	//len: record the length of one line
						//nlines: record the total lines
	char *p, line[MAXLEN];	//p: pointer returned from alloc
							//line: one line from getline() function

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)	
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL)	//check for wrong conditions
			return -1;
		else
		{
			line[len-1] = '\0';	//delete the '\n' character
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; ++i)
	{
		printf("%s\n", lineptr[i]);
	}
}

void swap(char *v[], int i, int j)	//swap pointers in pointer arrays
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(char *v[], int left, int right)	//sort the pointer arrays, just exchange the order of pointers
{
	int i, last;

	if (left >= right)		//return if the array contains less than 2 items;
		return;
	swap(v, left, (left + right)/2);	//chooose the median
	last = left;
	for (i=left+1; i<=right; ++i)	//partition
	{
		if (strcmp(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);	//restore the partition item
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

//sort input lines
main()
{
	int nlines;

	printf("Input lines, with EOF(ctrl-z) at the end of the lines\n" );
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0 , nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error\n");
		return 1;
	}
}
/* K&R exercise 3-1.
 * Write a bin-search with only one test inside the loop and measure the
 * difference in time between the version with two tests bin-search.
 * Yigwoo.
 * 2012-7-3.
 */
#include <stdio.h>
#include <time.h>
#define MAX_ELEMENT 20000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
int binsearch3(int x, int v[], int n);

main() {
  int testArray[MAX_ELEMENT];
  int index;
  int n = 39999;
  int i;
  clock_t time_taken;

  for (i = 0; i < MAX_ELEMENT; i++)
    testArray[i] = 2 * i + 1;

  for (i = 0, time_taken = clock(); i < 10000000; i++)
    index = binsearch(n, testArray, MAX_ELEMENT);
  time_taken = clock() - time_taken;
  
  if (index < 0)
    printf("Element not found\n");
  else
    printf("Element %d found at index %d.\n", n, index);
  printf("binsearch() took %lu clocks (%lu seconds)\n",
	 (unsigned long)time_taken,
	 (unsigned long)time_taken / CLOCKS_PER_SEC);

  for (i = 0, time_taken = clock(); i < 10000000; i++)
    index = binsearch2(n, testArray, MAX_ELEMENT);
  time_taken = clock() - time_taken;
  if (index < 0)
    printf("Element not found\n");
  else
    printf("Element %d found at index %d.\n", n, index);
  printf("binsearch2() took %lu clocks (%lu seconds)\n",
	 (unsigned long)time_taken,
	 (unsigned long)time_taken / CLOCKS_PER_SEC);

  for (i = 0, time_taken = clock(); i < 10000000; i++)
    index = binsearch3(n, testArray, MAX_ELEMENT);
  time_taken = clock() - time_taken;
  if (index < 0)
    printf("Element not found\n");
  else
    printf("Element %d found at index %d.\n", n, index);
  printf("binsearch3() took %lu clocks (%lu seconds)\n",
	 (unsigned long)time_taken,
	 (unsigned long)time_taken / CLOCKS_PER_SEC);
  
  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;
  
  low = 0; 
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else                  /* found match */
      return mid;
  }
  return -1;              /* no match */
}

int binsearch2(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  
  while (low <= high && x != v[mid]) {
    if (x < v[mid])
      high = mid - 1;
    else 
      low = mid + 1;
    mid = (low + high) / 2;
  }
  return (x == v[mid]) ? mid : -1;
}

int binsearch3(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  
  while(low < high) {
    mid = (low + high) / 2;
    if(x <= v[mid])
      high = mid;
    else 
      low = mid + 1;
  }
  
  return (x==v[low]) ? low : -1;
}

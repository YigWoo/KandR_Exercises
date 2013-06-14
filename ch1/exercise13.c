/*
 * A program to histogram of the lengths of words in its input. 
 * Compilation: gcc exercise13.c
 * Execution: ./a.out < test13
 * Input: plain text or standard input
 * Output: a vertical histogram with the x-axis the lengths of words and the y-axis the frequencies of words of respective length
 *
 * Author: Yigwoo
 * BTW, this is the first time that i feel so fulfilled when I'm doing my programming assignment!!
 * ^_^, really appreciate Code Complete and some other great books
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define IN 1			/* the state of being in a word */
#define OUT 0			/* the state of not being in a word */
#define MAXIMUM 11		/* the maximum of x-axis value */
/* I want a data structure which can represents the values of x, y axis of the histogram */
/* struct HistogramPoint { */
/*   int horizontalValue; */
/*   int verticalValue; */
/* } */

main() {
  int printHistogram(const int*);
  int tmpChar;
  int wordLength;
  int histogram[MAXIMUM];
  int returnCode;
  int i;

  wordLength = 0;
  returnCode = 0;
  tmpChar = 0;
  for (i = 0; i < MAXIMUM; i++)
    histogram[i] = 0;

  /* count the words of varied lengths */
  /* how to count the words? */
  /* while the input is not EOF */
  /* read in a character */
  while ((tmpChar = getchar()) != EOF) {
  /*   if the character is blank, tab or newline */
  /*     skip the character */
    if (tmpChar == ' ' | tmpChar == '\t' | tmpChar == '\n')
      continue;
  /*   else */
    else {
  /*     count and get the length of the word */
      returnCode = countWordLength(&wordLength);
      assert(wordLength > 0);
  /*     record the accurance of the word into the corresponding length column */
  /*     if the return code is -1, then it indicates the stream reaches the end */
  /*       to deal with it, record the length of the last word, and jump out of the loop */
      if (returnCode == 1) {
	if (wordLength < MAXIMUM)
	  histogram[wordLength-1]++;
	else
	  histogram[MAXIMUM-1]++;
	break;
      }
  /*     if the return code is 0, then just increment the value of corresponding x column */
      else {	
      if (wordLength < MAXIMUM) 
	histogram[wordLength-1]++;
      else
	histogram[MAXIMUM-1]++;
      }
    }
  }
  /* test the correctness of the above procedure to */
  /* for (i = 0; i < MAXIMUM; i++) */
  /*   printf("%d ", histogram[i]); */
  /* printf("\n"); */
  /* proceed the data of the appearance frequencies of words of respective length (if using the structrue implementation rather than array implementation) */
  /* the process is a sorting procedure, just sort the horizontalValue in HistogramPoint structure to get the final result */
  /* print the histogram */
  /* I think I should write a routine which prints histogram */
  printHistogram(histogram);
}

/* the routine print a histogram */
/* the input is an integer array that contains the values on the y-axis */
/* the index values are the values on x axis */
/* the output will be a printed vertical histogram */
int printHistogram(const int* valueArray) {
  int i;
  int xCount, yCount;
  int largestValueOfY;
  int ** bitMatrix;
  /* caculate the largest value of y axis */
  largestValueOfY = 0;
  for (i = 0; i < MAXIMUM; i++) {
    if(valueArray[i] > largestValueOfY)
      largestValueOfY = valueArray[i];
  }
  /* create a two dimension matrix with MAXIMUM and the largest value of y axis as respective limits */
  /* to allocate space for a two dimensional array, you have first allocate the row pointers, then allocate
   * the space for each position
   */
  bitMatrix = (int **) malloc(largestValueOfY * sizeof(int*));
  if (bitMatrix == NULL) {
    printf("Insufficient Space for bitMatrix!\n");
    exit(0);
  }
  for (i = 0; i < largestValueOfY; i++) {
    bitMatrix[i] = (int *) malloc(MAXIMUM * sizeof(int));
    if(bitMatrix[i] == NULL) {
      printf("Insufficient Space for bitMatrix[%d]!\n", i);
      exit(0);
    }
  }

  /* printf("%d\n",largestValueOfY); */
  /* process the matrix */
  /*   for every column of x axis, we assume the value of x is m, and n represents the value of the integeter array at m index */
  /*     sign every matrix slots at m column whose y value is less than n with 1 */
  /*     leave other slot with 0 */
  for (yCount = 0; yCount < largestValueOfY; yCount++)
    for (xCount = 0; xCount < MAXIMUM; xCount++) {
      if (valueArray[xCount] < (yCount + 1))
	bitMatrix[yCount][xCount] = 0;
      else
	bitMatrix[yCount][xCount] = 1;
    }

  /* for (yCount = 0; yCount < largestValueOfY; yCount++) { */
  /*   for (xCount = 0; xCount < MAXIMUM; xCount++) { */
  /*     printf("%d ", bitMatrix[yCount][xCount]); */
  /*   } */
  /*   printf("\n"); */
  /* } */

  /* print the matrix, if a slot of the matrix is filled with 1, then print a asterisk, else print a blank */
  for (yCount = largestValueOfY - 1; yCount >= 0; yCount --) {
    printf("%3d| ", yCount+1);
    for (xCount = 0; xCount < MAXIMUM; xCount++) {
      if (bitMatrix[yCount][xCount] == 1)
	printf(" * ");
      else 
	printf("   ");
    }
    printf("\n");
  }

  /* print the x axis */
  printf("   + ");
  for (xCount = 0; xCount < MAXIMUM; xCount++)
    printf("---");
  printf("\n    ");
  for (xCount = 0; xCount < MAXIMUM - 1; xCount++)
    printf("%3d", xCount+1);
  printf(" 10+\n");

  /* free the space allocated */
  for (i = 0; i < largestValueOfY; i++) 
    free(bitMatrix[i]);
  free(bitMatrix);
}

/* the routine count the length of a word */
/* the precondition is that the caller has read a character that is not blank, tab nor newline */
/* the input is a argument that is used to record the length of the word */
/* the postcondition is that the argument will be interpolated according to the length of the word */
/* if a EOF is detected after counting the word, a return code of 1 will be returned, otherwise a 0 will be returned */
int countWordLength(int *wordLength) {
  int c;
  /* according to the precondition, the initial value of the length of the word will be 1 */
  *wordLength = 1;
  /* well, because getchar() is line-buffed, if a EOF (C-d) is entered after some character, it acts like a linefeed to send the preceding
   * characters to the program, and if a EOF is used in a single line of stdin, it acts like the end of the stdin stream, so if you type 
   * something like:
   * abcd'C-d'
   * characters "abcd" will be flushed, but the stdin stream will not be closed, to close the stdin stream, you have to press another C-d:
   * like: abcd'C-d''C-d'
   * but, when EOF is used in the beginning of the single line, it will close the stdin stream, for instance:
   * abcdefg
   * 'C-d'
   * the last EOF will close the stdin stream
   */
  while ((c = getchar()) != EOF) {
    if(c == ' ' | c == '\t' | c == '\n')
      return 0;
    else 
      /* Caution: it seems that using *wordLength++ will not increment wordLength,
       *          because the preceden of operator ++ is a level higher that operator *, so *wordLength++ is actually evaluated as *(wordLength++) 
       */
      *wordLength += 1;
      /* printf("I'm here\n"); */
  }
  return 1;
}


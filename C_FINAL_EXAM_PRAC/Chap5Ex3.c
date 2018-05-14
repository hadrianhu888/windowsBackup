/*****
XINYU HADRIAN HU
29/04/2018
PROGRAM TO READ FROM FILE AND
SUM UP THE POSITIVE AND NEGATIVE NUMBERS
******/

//PREPROCESSORS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <time.h>

//MACROS

#define TRUE 1
#define FALSE 0
#define PI 3.14159
#define FILE_STRING 50

//FUNCTION PROTOTYPES

double pSum (FILE * ptr, double * p, int size);
double nSum (FILE * ptr, double * p, int size);

//MAIN BODY

int main (int arggc, char * argv [ ])
{
	//file reading variables

    FILE * ptrFile;
    char fileName [FILE_STRING];
    double * pS;
    double FileVal;
    char line;
    int counter = 0;
    int size;
    int i;
    double positiveSum;
    double negativeSum;
    //get file name

    FILE_NAME:

    printf ("\nPlease enter a valid file name >> ");
    scanf ("%s", fileName);
    ptrFile = fopen (fileName, "r+");
    if (ptrFile == NULL)
	{
		printf ("\nThis is not a valid file name. Please enter a valid file name. Press 0 to exit.\n\n");
		goto FILE_NAME;
	}
	else
	{
		printf ("\nThis is a valid file. The file name is called \"%s\".\n\n", fileName);
	}

    //count the number of lines in the file here
    for (line = getc (ptrFile); line != EOF; line = getc (ptrFile))
	{
        if (line == ' ' || line == '\n')
		{
			++counter;
			if (line == EOF)
			{
				break;
			}
		}
	}

	//here size of the array to be allocated has been determined

	size = counter;

	pS = (double * ) malloc (size * sizeof (double));
	if (pS == NULL)
	{
		printf ("\nNOT ENOUGH MEMORY!\n\n");
		exit (0);
	}

	//close the file here

    fclose (ptrFile);

    //reopen the file here

    ptrFile = fopen (fileName, "r+");

    pS = (double *) malloc (size * sizeof (double));

    size = counter;

    printf ("\nData in the File >> \n\n");

    for (i = 0; i < size; ++i)
	{
		fscanf (ptrFile, "%lf", &FileVal);
        pS [i] = FileVal;
        printf ("%d.\t%.3lf\n", (i + 1), pS [i]);
	}

	//print out the results here

	positiveSum = pSum (ptrFile, pS, size);
	negativeSum = nSum (ptrFile, pS, size);

	printf ("\n\n");

	free (pS);
    fclose (ptrFile);

	return (0);
}

//FUNCTION DEFINITIONS

double pSum (FILE * ptr, double * p, int size)
{
    char fileName [FILE_STRING];
	ptr = fopen (fileName, "w");
    int i;
    double sum = 0.0;
    for (i = 0; i < size; ++i)
	{
		if (p [i] > 0)
		{
			sum += p [i];
		}
	}
	printf ("\nSum of Positive Values >> %.3lf.\n", sum);
	fprintf (ptr,"\nSum of Positive Values >> %.3lf.\n", sum);
	fclose (ptr);
	return (sum);
}
double nSum (FILE * ptr, double * p, int size)
{
	char fileName [FILE_STRING];
	ptr = fopen (fileName, "w");
	int i;
	double sum = 0.0;
	for (i = 0; i < size; i++)
	{
		if (p [i] < 0)
		{
			sum += p [i];
		}
	}
	printf ("\nSum of Negative Values >. %.3lf.\n", sum);
	fprintf (ptr,"\nSum of Negative Values >> %.3lf.\n", sum);
	fclose (ptr);
	return (sum);
}



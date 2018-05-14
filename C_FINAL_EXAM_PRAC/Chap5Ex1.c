/****************************************************************************************************************
XINYU HADRIAN HU
C PROGRAM TO CALCULATE THE SUM OF POSITIVE AND NEGATIVE VALUES IN A GIVEN FILE
28/04/2018
TO USE MALLOC OR CALLOC PROPERLY,
RE-INSTANTIATE MALLOC OR CALLOC FUNCTION AFTER LINE COUNT FUNCTION HAS BEEN COMPLETED
****************************************************************************************************************/

//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//MACROS

#define MAX 200
#define FILEMAX 50
#define TRUE 1
#define FALSE 0

//FUNCTION PROTOTYPES

double negSum (double * p, int size);
double posSum (double * p, int size);

int main (int argc, char * argv [ ])
{
    //declare file variables

    FILE * ptrIn;
    FILE * ptrOut;

    //declaring file names variables

    char inFile [FILEMAX];
    char outFile [FILEMAX];
    char quit;

    //indexing variables

    int i = 0, j = 0;
    int tempW, tempR;

	tempW = i;
	tempR = j;

    //input variables

    double vals;
    double * pF;
    char line;
    int ctr = 0;
	double * pR;
    int size;
    double nSum;
    double pSum;

	//let the user enter a valid file name first

	printf ("\n\nPlease enter a valid file name, ending in either .txt or .dat >> ");
    scanf ("%s", inFile);
    printf ("\n\nYour file name >> %s.\n\n", inFile);
    ptrIn = fopen (inFile, "w");

    //determine the size of the array

    ARRAY_SIZE:

    printf ("\nEnter the size of the desired array >> ");
    scanf ("%d", &size);
    printf ("\nSize >> %d items in this array.\n\n", size);

    pF = (double *) malloc (size * sizeof (double));
    if (pF == NULL)
	{
		printf ("\nNOT ENOUGH MEMORY!\n");
		exit (0);
	}

	i = tempW;

    for (i = 0; i < size; ++i)
    {
        printf ("\nEnter %d of %d >> ", (i + 1), size);
        scanf ("%lf", &pF [i]);
    }

    printf ("\n\nThe Values entered into the file %s >> \n\n", inFile);

    for (i = 0; i < size; ++i)
	{
		printf ("%d.\t%.3lf\n", (i + 1), pF [i]);
		fprintf (ptrIn, "%.3lf\n", pF [i]);
	}

	free (pF);
	fclose (ptrIn);

    //this section opens up the original file and adds up the negative values - let the user enter a file name

    FILE_NAME_VERIFICATION:

    printf ("\n\nEnter the file to open >> ");
    scanf ("%s", outFile);
    ptrOut = fopen(outFile, "r");

    if (ptrOut == NULL)
	{
        printf ("\n\nThe file does not exist. Please enter a valid file name.\n");

        goto FILE_NAME_VERIFICATION;
	}
    fscanf (ptrOut, "%lf", &vals);

    for (line = getc (ptrOut); line != EOF; line = getc (ptrOut))
	{
        if (line == '\n' || line == '\t')
        {
        	++ctr;
        	if (line == EOF)
			{
				break;
			}
        }
	}
	size = ctr;

	printf ("\n\nNumber of Lines in File %s >> %d\n\n", outFile, size);

    pR = (double *) malloc (size * sizeof (double));
    if (pR == NULL)
	{
		printf ("\n\nNOT ENOUGH MEMORY!\n");
		exit (0);
	}
	size = ctr;

	fclose (ptrOut);

	//reopen the file here

	ptrOut = fopen (outFile, "r+");

	//prints out the values in the file here

	printf ("\nValues in the File >> \n\n");

	size = ctr;

	j = tempR;

	/*************************** call the pR memory allocation again and use a for loop instead ***************************/

	pR = (double * ) malloc (size * sizeof (double));

	for (j = 0; j < size; ++j)
	{
		fscanf (ptrOut, "%lf ", &vals);
		pR [j] = vals;
		printf ("%d.\t%.3lf\n", (j + 1), pR [j]);
	}

	//call the functions here

	pSum = posSum (pR, size);
	nSum = negSum (pR, size);

	//free the pointer from memory heap and close the file

	free (pR);
	fclose (ptrOut);

	return (0);
}

//define function definitions here
/****************************************************************************************************************/

double negSum (double * p, int size)

//sum of negative numbers

{
    double nSum = 0;

    int i;

    for (i = 0; i < size; i++)
	{
		if (p [i] < 0)
		{
			nSum += p [i];
		}
	}
	printf ("\nSum of Negative values = %.3lf.\n", nSum);

	return (nSum);
}

//sum of positive numbers

double posSum (double * p, int size)
{
	double pSum = 0;

    int i;

    for (i = 0; i < size; i++)
	{
		if (p [i] > 0)
		{
			pSum += p [i];
		}
	}
	printf ("\nSum of Positive values = %.3lf.\n", pSum);

	return (pSum);
}

/****************************************************************************************************************/


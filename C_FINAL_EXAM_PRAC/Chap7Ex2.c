/*****************************************************

XINYU HADRIAN HU
C PROGRAM TO READ FROM A FILE
AND LIST THE NUMBERS AND
DISPLAY MAX AND MIN VALUES FROM A FILE

*****************************************************/

//preprocessor directives

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//macro definitions

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define FILE_STR 500

//function prototypes

double largest (double* arr, int size, int * position);
double smallest (double * arr, int size, int * position);

int main (int argc, char * argv [ ])
{
	//variable declarations

	FILE * ptrFile;
	char fileName [FILE_STR];
    int i, j, k;
    int arraySize;
    double * arr;
    double arrVal;
    int size;

    double max;
    int maxPosition;
    double min;
	int minPosition;

    FILE_NAME:

    //get the file name, open the file, check that file exists

    printf ("\nEnter the name of your file >> ");
	scanf ("%s", fileName);
    ptrFile = fopen (fileName, "r");
	if (ptrFile == NULL)
	{
		printf ("\nThe file does not exist. Please enter a valid file name.\n\n");
		goto FILE_NAME;
	}

	//gets the information from the file and print out the contents of the file

    else
	{
		fscanf (ptrFile, "%d", &arraySize);
		size = arraySize;
        arr = (double *) malloc (size * sizeof (double));
        if (arr == NULL)
		{
			printf ("\nNOT ENOUGH MEMORY!\n\n");
			exit (1);
		}
		printf ("\nThe contents of the file >> \n\n");
        for (i = 0; i < size; ++i)
		{
            fscanf (ptrFile, "%lf\n", &arrVal);
            arr [i] = arrVal;
            printf ("%d.\t%.3lf\n", (i + 1), arr [i]);
		}
	}

	//call the function for max value

	max = largest (arr, size, &maxPosition);
	min = smallest (arr, size, &minPosition);

	free (arr);
    fclose (ptrFile);

	return (0);
}

double largest (double * arr, int size, int * position)
{
	int i, j, k;
    double max  = arr [0];
    for (i = 0; i < size; ++i)
	{
        if (arr [i] > max)
		{
			max = arr [i];
			* position = (i + 1);
		}
	}
	printf ("\nMaximum = %.3lf\n\nPosition = %d.\n\n", max,  * position);
}

double smallest (double * arr, int size, int * position)
{
	int i, j, k;
    double min = arr [0];
    for (i = 0; i < size; ++i)
	{
        if (arr [i] < min)
		{
			min = arr [i];
			* position = (i + 1);
		}
	}
	printf ("\nMinimum = %.3lf\n\nPosition = %d.\n\n", min,  * position);
}

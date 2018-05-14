//preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

//macros

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define STRING_MAX 100

//function definitions

double negSum (double * p, int size);

//program to read a 1-D array from file and add up only the negative numbers

int main (int argc, char * argv [])
{
    FILE *ptrOpen;

    char fileName [STRING_MAX];
    double * pData;
    int lines = 0;
    char line_char;
    double arrData;
    int size;
    int i;

    FILE_NAME_INPUT:

    printf ("\nPlease enter a valid file name: ");
    scanf ("%s", fileName);

    ptrOpen = fopen (fileName, "r");

    if (ptrOpen == NULL)
	{
		printf ("\nThe file does not exist. Please enter another file name.");
		goto FILE_NAME_INPUT;
	}
	else
	{
		printf ("\nThis is a valid file name. The file is %s.\n", fileName);
	}

	//display the content of the file here - first count how many lines are in the file itself

    for (line_char = getc(ptrOpen); line_char != EOF; line_char = getc(ptrOpen))
	{
		if (line_char == '\n' || line_char == ' ')
		{
			++lines;
		}
	}

	//set size to be equal to number of lines counted in the file

	size = lines;

	pData = (double *) malloc (size * sizeof (double));
	if (pData == NULL)
	{
		printf ("\nNot enough memory!\n");
        exit (1);
	}

	free(pData);
	fclose (ptrOpen);

	ptrOpen = fopen (fileName, "r");
	pData = (double *) malloc (size * sizeof (double));


	for (i = 0; i < size; ++i)
	{
		fscanf (ptrOpen, "%lf\n", &arrData);
		pData [i] = arrData;
		printf ("%d.\t%.3lf\n", (i + 1), pData [i]);
	}

	free(pData);
	fclose (ptrOpen);

	return (0);
}


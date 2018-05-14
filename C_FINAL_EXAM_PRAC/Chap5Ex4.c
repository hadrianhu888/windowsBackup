/*********************************************
XINYU HADRIAN HU
29/04/2018
PROGRAM TO READ FROM FILE AND
SUM OF WHOLE INTEGER VALUES IN A FILE ONLY
*********************************************/

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

#define DIV_1 7
#define DIV_2 11

//FUNCTION PROTOTYPES

void printIntSum (double * p, int size);

int main (int argc, char * argv [ ])
{
    FILE *ptrFile;
    char fName [FILE_STRING];
    int i, j, k;
    char line;
    int count = 0;
    int size;
    double * ptr_File;
    double fileVal;

    //get file name

    FILE_CHECK:

    printf ("\nEnter the name of your file >> ");
    scanf ("%s", fName);
    ptrFile = fopen (fName, "r+");

    //check if the file exists
    if (ptrFile == NULL)
	{
		printf ("\nThe file does not exist. Please enter a valid file name.\n");
		goto FILE_CHECK;
	}
	else
	{
		printf ("\nThe file exists. The name of the file is >> \"%s.\"\n\n", fName);
	}

	//count the "lines" or spaces here
    do
	{
        if (line == ' ' || line == '\n' || line == '\t')
		{
			++count;
			if (line == EOF)
			{
				break;
			}
		}
		line = getc (ptrFile);

	} while (line != EOF);

	size = count;

    ptr_File = (double * ) malloc (size * sizeof (double));
    if (ptr_File == NULL)
	{
		printf ("\nNOT ENOUGH MEMORY!\n\n");
		exit (1);
	}

	free (ptr_File);
	fclose (ptrFile);

	/*********************************************************************************/

	ptrFile = fopen (fName, "r+");
	ptr_File = (double * ) malloc (size * sizeof (double));

	printf ("\nData in the text file %s are >> \n\n", fName);

	for (i = 0; i < size; ++i)
	{
		fscanf (ptrFile, "%lf", &fileVal);
		ptr_File [i] = fileVal;
		printf ("%d.\t%lf\n", (i + 1), ptr_File [i]);
	}

	printf ("\nOnly printing out the whole integer values in %s >> \n\n", fName);

	for (i = 0; i < size; ++i)
	{
		if ((int) ptr_File [i] == ptr_File [i])
		{
			printf ("%d.\t%d\n", (i + 1), (int) ptr_File [i]);
		}
	}

	PositiveSum (ptr_File, size);

	free (ptr_File);

	fclose (ptrFile);

	return (0);
}

//returns the positive sum of the whole values
void PositiveSum (double * p, int size)
{
    int i;
    int sum = 0;
    for (i = 0; i < size; ++i)
	{
        if ((int) p [i] == p [i])
		{
            sum += p [i];
		}
	}
	printf ("\nSum of the whole integer values is >> %d.\n\n", sum);
}

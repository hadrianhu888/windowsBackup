/*********************************************

XINYU HADRIAN HU
29/04/2018
PROGRAM TO READ FROM FILE AND
PRINT OUT ONLY THOSE NUMBERS THAT ARE DIVISIBLE
BY EITHER SEVEN (7) OR ELEVEN (11)

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

//GLOBAL VARIABLES

FILE * ptrFile;
double * pRead;
double fileVals;
char fName [FILE_STRING];
int size;

//FUNCTION PROTOTYPES

void getFileName (void);
void countLines (void);
void printData (double * p, int size);
void printDivs (double * p, int dim);

//PROGRAM START

int main (int argc, char * argv [ ])
{
	//get file name
	getFileName ();

	//print file data
	countLines ();

	//print the data here
	printData (pRead, size);

	//print divisors here
	printDivs (pRead, size);

	return (0);
}
//get the file name
void getFileName (void)
{
    //get file name in this function

    FILE_NAME:

    printf ("\nEnter the name of your file >> ");
    scanf ("%s", fName);

    //open the file here to make sure it exists

    ptrFile = fopen (fName, "r");

    if (ptrFile == NULL)
	{
        printf ("\nThe file does not exist. Please enter a valid file name.\n\n");
        goto FILE_NAME;
	}
}

//count lines in the file
void countLines (void)
{
    ptrFile = fopen (fName, "r");
    char line;
    int count = 0;
    for (line = getc (ptrFile); line != EOF; line = getc (ptrFile))
	{
		if (line == '\t' || line == ' ' || line == '\n' || line == '\b')
		{
			++count;
			if (line == EOF)
			{
				break;
			}
		}
	}
	size = count;

    pRead = (double * ) calloc (size, sizeof (double));

    free (pRead);
    fclose (ptrFile);

}

//print out the data in the file
void printData (double * p, int size)
{

    printf ("\nThe data in file %s >> \n\n", fName);

    int i, j, k;

    ptrFile = fopen (fName, "r");
	pRead = (double * ) calloc (size, sizeof (double));

	for (i = 0; i < size; ++i)
	{
        fscanf (ptrFile, "%lf", &fileVals);
        p [i] = fileVals;
        printf ("%d.\t%.3lf\n", (i + 1), p[i]);
	}

	free (pRead);
    fclose (ptrFile);
}


//print out the numbers that are divisible by either 7 or 11

void printDivs (double * p, int dim)
{
	int i, j, k;

	printf ("\nNumbers divisible by either %d or %d >> \n\n", DIV_1, DIV_2);

	ptrFile = fopen (fName, "r");
	pRead = (double * ) calloc (size, sizeof (double));

	for (i = 0; i < size; ++i)
	{
        fscanf (ptrFile, "%lf", &fileVals);
        p [i] = fileVals;
        if (((int) p [i] % DIV_1 == 0) || ( (int) p [i] % DIV_2 == 0))
		{
            printf ("%d.\t%d\n", (i + 1), (int) p [i]);
		}
	}
    free (pRead);
	fclose (ptrFile);
}

/*****************************************************************************

XINYU HADRIAN HU
500194233
CPS 125
SECTION 29

C PROGRAM TO CALCULATE NORM AND STD BY READING FROM FILE

25032018
RYERSON UNIVERSITY

*****************************************************************************/

//including preprocessor directives

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

//defining MACROs

#define PI 3.14159
#define ARRMAX 5000
#define STRMAX 500

#define SPACE printf ("\n");
#define LINE printf ("------------------------------------------------------------------------------");
#define DOUBLESPACE printf ("\n\n");
#define SLS SPACE; LINE; SPACE;

//defining function prototypes

void getTitle ( );
void getFileName ( );
double maxArr ( double arr [], int size, int * locArr );
double minArr ( double arr [], int size );
double sumArr ( double arr [], int size );
double avgArr ( double arr [], int size );

//start of main program

int main ( int argc, char * argv [ ] )
{
	//declaring variables for file reading

	getTitle ( );

    //check that the file exists and return with a goto loop to ask again if the file is not found

    getFileName ( );

	return (0);
}

void getTitle ( )

//get the title
{
	printf ("NORMALIZATION AND STANDARDIZATION CALCULATOR BASED ON A FILE");
    SLS;
}

void getFileName ( )

//get the file name
{
	FILE * ptrFile;

    char fileName [STRMAX];
    char line;
    double fileArray [ARRMAX];

    int i, j, k;
    int count = 0;
    int iter = 0;

    double fileValue;

    FILENAME:

    printf ("Please enter the name of your file >> ");
    scanf ("%s", &fileName);
    printf ("\nFile Name >> %s\n", fileName);

    if ( ptrFile = (fopen (fileName, "r+") == NULL) )
	{
		//get the file name

		printf ("Sorry, the file does not exist. Please enter a valid file name.");
		SPACE;
		goto FILENAME;
	}

    else if ((ptrFile = fopen (fileName, "r+")) != NULL)
	{
		SPACE;
		printf ("The Entries from the file are >> ");
		SLS;

		for ( line = getc (ptrFile); line != EOF; line = getc (ptrFile))
		{
			if (line == '\n' || line == ' ' || line == '\t' || line == ',')
			{
				++count;
			}
		}

		fclose (ptrFile);

		int size = count - 1;

		//stores every number into the array and prints out the information from the file

		/*************************************************************************
		The numbers in the file are not being written into the array correctly
		*************************************************************************/
		ptrFile = fopen (fileName, "r+");

            //use fscanf, read the file and update again using fscanf until EOF
			while ((fscanf (ptrFile, "%lf\n", &fileValue)) != EOF)
			{
				for (i = 0; i < size; ++i)
				{
					fscanf (ptrFile, "%lf\n", &fileValue);
					fileArray [i] = fileValue;
					printf ("%d.\t%.3lf\n", (i + 1), fileArray [i]);
				}
			fscanf (ptrFile, "%lf\n", &fileValue);
			}

		double maxValue;
		int locArr;

		maxValue = maxArr (fileArray, size, &locArr);

		printf("\nMax Value of Array is >> %.3lf @ i = %d\n\n", maxValue, locArr);

	fclose (ptrFile);
	}
}

double maxArr (double arr [], int size, int * locArr)
{
	int i;
	double max;
    for (i = 0; i < size; ++i)
	{
        if (arr[i] > max)
		{
			max = arr[i];
			*locArr = (i + 1);
		}
	}

	return (max);
}

double minArr (double arr [], int size)
{
	int i;
	double min;
	int locArr;
    for (i = 0; i < size; ++i)
	{
        if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return (min);
}

double sumArr (double arr [], int size)
{
	int i;
	double sum;
	for (i = 0; i < size; ++i)
	{
        sum += arr [i];
	}
	return (sum);
}

double avgArr ( double arr [], int size )
{
    int i;
    double sum;

    sum = sumArr (arr, size);
    double avg;

	avg = sum / size;

	return (avg);
}





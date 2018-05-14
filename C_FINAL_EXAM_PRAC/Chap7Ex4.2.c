/***************************************************************************

XINYU HADRIAN HU
500194233
07/05/2018
C PROGRAM TO GENERATE A TWO-DIMENSIONAL ARRAY
AND WRITE TO FILE
THEN READ THE SAME FILE IN THE SAME PROGRAM

***************************************************************************/

//preprocessors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//macros

#define STRING_MAX 50

//function prototypes

void printMajorDiagonal (double ** m, int r, int c);
void printMinorDiagonal (double ** m, int r, int c);

int main (int argc, char * argv [ ])
{
    FILE * ptrIn;
    FILE * ptrOut;

    char inFileName [STRING_MAX];
    char outFileName [STRING_MAX];

    int row;
    int col;

    int r;
    int c_temp;
    int c;

    char spaces;
    char lines;
    char ch;

    int i, j, k;

    int ctrSpaces = 0;
    int ctrLines = 0;
    int ctrH = 0;
    int ctrV = 0;
    int charCount = 0;
    int lineCount = 0;

    double matrixVals;
    double ** matrixIn;
    double ** matrixOut;

    //get a file name first

    printf ("\nEnter a file name >> ");
    scanf ("%s", inFileName);

    //open the file

    ptrIn = fopen (inFileName, "w");

    //get matrix dimensions

    printf ("\nEnter the row and column sizes >> ");
    scanf ("%d", &row);
    scanf ("%d", &col);
    printf ("\nRows >> %d\nCols >> %d\n\n", row, col);

    matrixIn = (double **) malloc (row * sizeof (double *));
    if (matrixIn == NULL)
	{
        printf ("\nSORRY, NOT ENOUGH MEMORY!\n\n");
        exit (0);
	}
	for (i = 0; i < row; i ++ )
	{
        matrixIn [i] = (double *) malloc (col * sizeof (double));
        if (matrixIn [i] == NULL)
		{
			printf ("\nSORRY, NOT ENOUGH MEMORY!\n\n");
			exit (0);
		}
	}

    //input the values into the matrix

    printf ("\nEnter the values into the matrix >> \n\n");

    for (i = 0; i < row; i ++)
	{
		for (j = 0; j < col; j ++)
		{
			printf ("\n\nEnter [%d][%d] of [%d][%d] >> ", (i + 1), (j + 1), row, col);
			scanf ("%lf", &matrixIn [i] [j]);
		}
	}

	//print out the matrix

	printf ("\nElements in the matrix >> \n\n");
    for (i = 0; i < row; i ++)
	{
		for (j = 0; j < col; j ++)
		{
			printf ("%.3lf\t", matrixIn [i][j]);
			fprintf (ptrIn, "%.3lf\t", matrixIn [i][j]);
		}
        printf ("\n");
        fprintf (ptrIn, "\n");
	}
	printf ("\n");
	fprintf (ptrIn, "\n");

	for (i = 0; i < row; i ++)
	{
		free (matrixIn [i]);
	}
	free (matrixIn);

    fclose (ptrIn);

    printf ("\n-----------------------------------------------------------------------------------------------------------------\n\n");

    /**------------------------------------------------------------------------------------------------------------------------------------------------------------------------------**/

    //now retrieve the file by first getting user input for file name and check that the file exists

    FILE_CHECK:

	printf ("\nEnter the name of file to access >> " );
	scanf ("%s", outFileName);
	printf ("\nThe name of the file is >> %s\n\n", outFileName);

	//now open the file and check that it exists

	ptrOut = fopen (outFileName, "r");
	if (ptrOut == NULL)
	{
		printf ("Sorry, the file does not exist. Re-enter another file-name.\n\n");
		goto FILE_CHECK;
	}

	/*******************************************************************************************************************************************/

	//read lines first - total number of lines == total number of rows

    for (lines = getc (ptrOut); lines != EOF; lines = getc (ptrOut))
	{
        if (lines == '\n')
		{
			ctrLines ++ ;
		}
	}

	r = ctrLines - 1;

    matrixOut = (double **) malloc (r * sizeof (double *));
    if (matrixOut == NULL)
	{
        printf ("\nSorry, not enough memory!\n\n");
        exit (0);
	}

    free (matrixOut);

    printf ("\nRows >> %d\n\n", r);

    /*******************************************************************************************************************************************/

    //open the file again to count columns

    ptrOut = fopen (outFileName, "r");

    for (spaces = getc (ptrOut); spaces != EOF; spaces = getc (ptrOut))
	{
		if (spaces == ' ' || spaces == '\t' || spaces == '\b')
		{
			ctrSpaces ++ ;
		}
	}

    c_temp = ctrSpaces;

    c = c_temp / r;

    printf ("\nCols >> %d\n\n", c);

	for (i = 0; i < r; i ++)
    {
		matrixOut [i] = (double *) malloc (c * sizeof (double));
		if (matrixOut [i] == NULL)
		{
			printf ("\nSorry, not enough memory!\n\n");
			exit (0);
		}
    }

    for (i = 0; i < r; i ++ )
	{
		free (matrixOut [i]);
	}
    fclose (ptrOut);

    //reopen the file again to read the matrix elements line by line

    ptrOut = fopen (outFileName, "r");

    matrixOut = (double **) malloc (r * sizeof (double *));

    for (i = 0; i < r; i ++)
	{
		matrixOut [i] = (double *) malloc (c * sizeof (double));
	}

	//print out the matrix here

	printf ("\nThe matrix in the file %s of size %d x %d.\n\n", outFileName, r, c);

    for (i = 0; i < r; i ++)
	{
		for (j = 0; j < c; j++)
		{
			fscanf (ptrOut, "%lf", &matrixVals);
			matrixOut [i] [j] = matrixVals;
            printf ("%.3lf\t", matrixOut [i] [j]);
		}
		printf ("\n");
	}
	printf ("\n");

	printMajorDiagonal (matrixOut, r, c);
	printMinorDiagonal (matrixOut, r, c);

	for (i = 0; i < r; i ++)
	{
		free (matrixOut [i]);
	}
	free (matrixOut);

	fclose (ptrOut);

	return (0);
}

//function definitions

void printMajorDiagonal (double ** m, int r, int c)
{
    //prints out the major diagonal
    int i, j;
	if (r == c)
	{
		printf ("\nMajor Diagonal >> \n\n");
		for (i = 0; i < r; i ++)
		{
			printf ("%.3lf\t", m [i] [i]);
		}
		printf ("\n");
	}
	else if (r != c)
	{
		printf ("\nThe major diagonal cannot be printed since the given matrix is not a square matrix.\n\n");
	}
}

void printMinorDiagonal (double ** m, int r, int c)
{
    //prints out the opposite "minor" diagonal
    int i, j;
    if (r == c)
	{
		printf ("\nMinor Diagonal >> \n\n");
		for (i = 0; i < r; i ++)
		{
			printf ("%.3lf\t", m [r - i - 1] [i]);
		}
		printf ("\n");
	}
	else if (r != c)
	{
		printf ("\nThe major diagonal cannot be printed since the given matrix is not a square matrix.\n\n");
	}
}






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

void printDiagonal (double ** m, int r, int c);

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

    int i, j, k;

    int ctrSpaces = 0;
    int ctrLines = 0;
    int ctrH = 0;
    int ctrV = 0;

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

    FILE_NAME:

	printf ("\nEnter the name of file to access >> ");
	scanf ("%s", outFileName);
    printf ("\nThe name of the file is >> %s\n\n", outFileName);

    //now open the file

    ptrOut = fopen (outFileName, "r");

    //check that the file exists

    if (ptrOut == NULL)
	{
		printf ("\nSORRY, THE FILE DOES NOT EXIST. PLEASE ENTER A VALID FILE NAME.\n\n");
		goto FILE_NAME;
	}

	//get the number of rows and columns

    for (lines = getc (ptrOut); lines != EOF; lines == getc (ptrOut))
	{
		if (lines == '\t' || lines == ' ')
		{
            ctrLines ++;
            if (lines == EOF)
			{
				break;
			}
		}
	}

	c_temp = ctrLines;

    for (spaces = getc (ptrOut); spaces != EOF; spaces = getc(ptrOut))
	{
        if (spaces == '\n')
		{
			ctrSpaces ++;
			if (spaces == EOF)
			{
				break;
			}
		}
	}

	r = ctrSpaces;

    //total number of columns is:

    c = c_temp / r;

    printf ("\nNumber of rows >> %d\n\nNumber of columns >> %d\n\n", r, c);

	matrixOut = (double **) malloc (r * sizeof (double *));
    if (matrixOut == NULL)
	{
		printf ("\nSorry, not enough memory!\n\n");
		exit (0);
	}

	for (i = 0; i < r; i ++)
	{
		matrixOut [i] = (double *) malloc (c * sizeof (double));
		if (matrixOut [i] == NULL)
		{
			printf ("\nSorry, not enough memory!\n\n");
			exit (0);
		}
	}

	for (i = 0; i < r; i ++)
	{
		free (matrixOut [i]);
	}
	free(matrixOut);

    fclose (ptrOut);

    //reopen the file and get the information from the file

    ptrOut = fopen (outFileName, "r");

    matrixOut = (double **) malloc (c * sizeof (double *));

    for (i = 0; i < r; i++)
	{
		matrixOut [i] = (double *) malloc (c * sizeof (double));
	}

	printf ("\nMatrix from File %s of dimensions %d X %d >>\n\n", outFileName, r, c);

    for (i = 0; i < r; i ++)
	{
		for (j = 0; j < c; j ++)
		{
            fscanf (ptrOut, "%lf", &matrixVals);
            matrixOut [i] [j] = matrixVals;
            printf ("%.3lf\t", matrixOut [i] [j]);
		}
		printf ("\n");
	}
	printf ("\n");

	for (i = 0; i < r; i ++)
	{
		free (matrixOut [i]);
	}
	free(matrixOut);

    fclose (ptrOut);

	return (0);
}


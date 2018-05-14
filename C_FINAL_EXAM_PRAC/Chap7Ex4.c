/*****************************************************

XINYU HADRIAN HU
MAY 5, 2018
C PROGRAM TO PRINT OUT A MATRIX FROM A FILE
AND PRINT OUT THE MAIN DIAGONALS IF AND ONLY IF
THE MATRIX IS A SQUARE MATRIX OF N X N SIZE BY
FIRST CHECKING ROW AND COLUMN DIMENSIONS

*****************************************************/

//preprocessors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>

//macros

#define TRUE 1
#define FALSE 0
#define PI 3.14159
#define FILE_STR_MAX 50

//function prototypes

void printMajorDiagonal (double ** p, int r, int c);

//start of the program

int main (int argc, char * argv [ ])
{

    //variables for file reading

    FILE * ptrFile;

    char fileName [FILE_STR_MAX];

    char lines;
    char spaces;

    int countL = 0;
    int countS = 0;

    int colTemp;

    int row, col;

    double ptrMatrixVals;

    int i, j, k;

	double ** ptrMatrix;

    //get a file name from the user

    FILE_NAME_INPUT:

    printf ("\nEnter a valid file name >> ");
    scanf ("%s", fileName);

	//open the file here

    ptrFile = fopen (fileName, "r");

    //verify that the file exists

    if (ptrFile == NULL)
	{
		printf ("\nSorry, the file does not exist. Please enter another file name.\n\n");
		goto FILE_NAME_INPUT;
	}

	//get the number of rows and columns in the file
	for (lines = getc (ptrFile); lines != EOF; lines = getc (ptrFile))
	{
		if (lines == ' ' || lines == '\t' || lines == '\b' || lines == '\0')
		{
			++countL;
			if (lines == EOF)
			{
				break;
			}
		}
	}
	colTemp = countL;
	//count columns
	for (spaces = getc (ptrFile); spaces != EOF; spaces = getc (ptrFile))
	{
		if (spaces == '\n')
		{
			++countS;
			if (spaces == EOF)
			{
				break;
			}
		}
	}
	//total of rows and columns are now known
	row = countS;

	col = colTemp / row;

	printf ("\nRows >> %d\n\nCols >> %d\n\n", row, col);

    //check if the matrix in the file is a square matrix or a rectangular matrix

    if (row == col)
	{
		printf ("\nThe matrix in the file %s is a square matrix of dimensions %d X %d.\n\n", fileName, row, col);
	}
	else if (row != col)
	{
        printf ("\nThe matrix in the file %s is a rectangular matrix of dimensions %d X %d.\n\n", fileName, row, col);
	}
    ptrMatrix = (double **) malloc (row * sizeof (double *));
    if (ptrMatrix == NULL)
	{
		printf ("\nSORRY, NOT ENOUGH MEMORY!\n\n");
		exit (1);
	}
	for (i = 0; i < row; i++)
	{
		ptrMatrix [i] = (double *) malloc (col * sizeof (double));
		if (ptrMatrix [i] == NULL)
		{
			printf ("\nSORRY, NOT ENOUGH MEMORY!\n\n");
			exit (1);
		}
	}
	//close the file here

	/***for (i = 0; i < row; i++)
	{
		free (ptrMatrix [i]);
	}
	free (ptrMatrix);

    fclose (ptrFile);***/

    //reopen the file here to read the values and print the values to the screen

    ptrFile = fopen (fileName, "r");

	ptrMatrix = (double **) malloc (row * sizeof (double *));

    for (i = 0; i < row; i++)
	{
		ptrMatrix [i] = (double *) malloc (col * sizeof (double));
	}

	printf ("\nValues in the Matrix: \n\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
            fscanf (ptrFile, "%lf", &ptrMatrixVals);
            ptrMatrix [i] [j] = ptrMatrixVals;
            printf ("%lf\t", ptrMatrix [i] [j]);
		}
		printf ("\n");
	}
	printf ("\n");

    for (i = 0; i < row; i++)
	{
		free (ptrMatrix [i]);
	}
	free (ptrMatrix);

    fclose (ptrFile);

	return (0);
}

//function definitions - this function print out the major diagonal of the matrix

void printMajorDiagonal (double ** p, int r, int c)
{
	int i, j;
}

//end of the program

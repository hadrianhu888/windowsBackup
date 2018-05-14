/***************************************************************************

XINYU HADRIAN HU
500194233
10/05/2018
C PROGRAM TO GENERATE A TWO-DIMENSIONAL ARRAY
AND WRITE TO FILE
THEN READ THE SAME FILE IN THE SAME PROGRAM

***************************************************************************/

	//preprocessors

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <windows.h>

	//macros

	#define STRING_MAX 50

	//global variables

	FILE * ptrFile;
	char fileName [STRING_MAX];
	char lines, spaces;
	int line, space;
	int ctrLines = 0, ctrSpaces = 0;
	char ch;
	int i, j;
	int row, col;
	double matVals;
	double ** matrix;

	//function prototypes

	void getFileName (FILE * ptrF);
	void openFile (FILE * ptrF, char fileN []);
	void readLines (FILE * ptrF, char fileN [], double ** m);
	void readSpaces (FILE * ptrF, char fileN [], double ** m, int * r);
	void rowAlloc (FILE * ptrF, char fileN [], double ** m, int * l);
	void colAlloc (FILE * ptrF, char fileN [], double ** m, int * r, int * s);
	void printSolution (FILE * ptrF, char fileN [], int r, int c);

	void printMajorDiagonal (double ** m, int r, int c);
	void printMinorDiagonal (double ** m, int r, int c);

	//start of the program

	int main (int argc, char * argv [])
	{
		//start of the program

		getFileName (ptrFile);
		openFile (ptrFile, fileName);
		readLines (ptrFile, fileName, matrix);
		readSpaces (ptrFile, fileName, matrix, &row);

		printSolution (ptrFile, fileName, row, col);

		return (0);
	}
	//get the file name
	void getFileName (FILE * ptrF)
	{
		printf ("\nEnter the name of the file you want to open >> ");
		scanf ("%s", fileName);
	}

	//open the file
	void openFile (FILE * ptrF, char fileN [])
	{
		ptrF = fopen (fileN, "r");
		if (ptrF == NULL)
		{
			printf ("Sorry, the file does not exist. Please enter a valid file name.\n\n");
			getFileName (ptrF);
		}
		else
		{
			printf ("\nName of the file >> %s.\n\n", fileN);
		}
	}
	//read lines - rows
	void readLines (FILE * ptrF, char fileN [], double ** m)
	{
		ptrF = fopen (fileN, "r");

		char l;
		int ctrL = 0;
		int r;
		int lVal;

		for (l = getc (ptrF); l != EOF; l = getc (ptrF))
		{
			if (l == '\n')
			{
				++ctrL;
			}
		}
		lVal = ctrL - 1;

		rowAlloc(ptrF, fileN, m, &lVal);

		fclose (ptrF);
	}
	//allocate memory for row
	void rowAlloc (FILE * ptrF, char fileN [], double ** m, int * l)
	{
		int r = * l;

		m = (double **) calloc (r, sizeof (double *));
		if (m == NULL)
		{
			printf ("\nSorry, not enough memory!\n\n");
			exit (0);
		}

		printf ("\nRows >> %d.\n", r);

		free (m);
	}
	//read spaces - columns --> columns = total spaces / number of rows
	void readSpaces (FILE * ptrF, char fileN [], double ** m, int * r)
	{
		ptrF = fopen (fileN, "r");

		char s;
		int i;
		int ctrS = 0;
		int c;
		int cVal;

		for (s = getc (ptrF); s != EOF; s = getc (ptrF))
		{
			if (s == ' ' || s == '\t' || s == '\b')
			{
				++ctrS;
			}
		}
		cVal = ctrS / * r;

		colAlloc (ptrF, fileN, m, r, &cVal);

		/**something is not working here so the program is giving a run-time error once it needs to read column**/

		fclose (ptrF);
	}

	//allocate memory for column
	void colAlloc (FILE * ptrF, char fileN [], double ** m, int * r, int * s) //file pointer, file name, matrix, reference row, space count;
	{
		int i;
		int c;

		c = * s;

		for ( i = 0; i < * r; i ++ )
		{
			m [i] = (double *) calloc (c, sizeof (double));
			if (m [i] == NULL)
			{
				printf ("\nSorry, not enough memory!\n\n");
				exit (0);
			}
		}
		printf ("Cols >> %d.\n\n", c);

		for (i = 0; i < * r; i ++)
		{
			free (m [i]);
		}

	}

	void printSolution (FILE * ptrF, char fileN [], int r, int c)
	{

	}

	void printMajorDiagonal (double ** m, int r, int c)
	{

	}
	void printMinorDiagonal (double ** m, int r, int c)
	{

	}

/*

XINYU HADRIAN HU
500194233
RYERSON UNIVERSITY
WINTER 2018
CPS 125 PROJECT 2
MATRICES PROJECT

READ FROM FILE AND CALCULATE CORNERS, BORDERS,
THE SUM OF ALL ROWS AND COLUMNS,
MAIN DIAGONAL and ANTI-DIAGONAL
AVERAGE VALUE OF THE ENTIRE MATRIX

*/

//including preprocessor directives

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

//defining MACROS

#define MIN 2
#define MAX 200
#define FILENAME 100
#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define ANGLE 180
#define CIRCLE 360
#define DRAD PI / ANGLE //deg to rad
#define RDEG ANGLE / PI	//rad to deg

//function prototypes

//start of program

int main (int argc, char * argv [])

{
    //declare variables here for file reading
    FILE * ptrFile;
    char fName [FILENAME];
    int r, c;
    int i, j;
    int rv, cv;
    int * r_calc;
    int * c_calc;
    double mat [MAX] [MAX];
    double matVal;

    //to count how many new lines there is
    char line;
    int count = 0;
    int line_index [MAX];

	//name of the project is here
    printf ("\nMATRIX CALCULATOR CPS 125 PROJECT 2\n\n");

    //get user input
    FILE_NAME:
    printf ("Enter the name of your file >> ");
    scanf ("%s", &fName);
    ptrFile = fopen (fName, "r");
    //check that the file exists
    if (ptrFile == NULL)
	{
		printf ("Invalid file name! Please enter a valid file name.\n\n");
		goto FILE_NAME;
	}
	else
	{
        //read the file's first two values to determine size of row and corners
        printf ("\nFile Name: %s.\n\n", fName);

        //read the rows and column size
        fscanf (ptrFile, "%d %d", &r, &c);
        {
			if ((r < MIN && c < MIN) && (r > MAX && c > MAX))
			{
				printf ("\nMatrix must be at least %d X %d to no more than %d X %d.\n\n", MIN, MIN, MAX, MAX);
				goto FILE_NAME;
			}
			printf ("The dimensions of the given matrix is: %d X %d.\n\n", r, c);
			if (r == c)
			{
				printf ("This is a square matrix of dimensions %d X %d.\n\n", r, c);
			}
			else
			{
				printf ("This is a rectangular matrix of dimensions %d X %d.", r, c);
			}
        }
        for (line = getc (ptrFile); line != EOF; line = getc (ptrFile))
		{
			if (line == '\n')
			{
				++count;
			}
		}
		fclose (ptrFile);
/********************************************************************************************************************/
		//reopen the file
		ptrFile = fopen (fName, "r");
		printf ("\n\nLines = %d\n\n", count);

		//reset count to 0
		count = 0;
		printf ("The matrix in the file is:\n\n");
		double status = fscanf (ptrFile, "%lf", &matVal);
        while ((fscanf (ptrFile, "%lf ", &matVal)) != EOF)
		{
			for (i = 0; i < r; ++i)
			{
				for (j = 0; j < c; ++j)
				{
					fscanf (ptrFile, "%lf ", &matVal);
					mat [i] [j] = matVal;
					printf ("%.3lf\t\t", mat [i] [j]);
					if (j > c)
					{
						break;
					}
				}
				if (i > r)
				{
					break;
				}
				fscanf (ptrFile, "\n");
				printf("\n");
			}

			//printf ("\n%lf\n%lf\n", mat [3][0], mat [4][0]);

			//keep reading the file until it reaches the last two integers and then break
			fscanf (ptrFile, "%lf ", &matVal);
			while ((fscanf (ptrFile, "%d\n%d\n", &rv, &cv)) != EOF)
			{
				fscanf (ptrFile, "\n%d\n%d", &rv, &cv);
				//r_calc = &rv;
				//c_calc = &cv;
				printf ("\nRow to Sum >> %d\nCol to Sum >> %d\n\n", rv, cv);
				break;
			}
		}
		fclose (ptrFile);
	}
	return (0);
}

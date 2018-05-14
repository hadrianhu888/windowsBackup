/*************************************************

XINYU HADRIAN HU
28/04/2018
C PROGRAM TO DETERMINE TOTAL COST OF ORDERS
AND TOTAL COST OF ALL THE ORDERS GIVEN FROM A
PREWRITTEN DATA FILE

*************************************************/

//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//MACROS

#define MAX_ARR 500
#define FILE_N 50
#define STRING_MAX 100

//STRUCTURE DEFINITIONS

typedef struct products
{

	long long int units;
	double cost;

} prodCost;

//GLOBAL VARIABLES

FILE * fName;
char fileName [STRING_MAX];
int count = 0;
char lines;
int size;

int * prod;
int ** orderUnits;

int prods;
int orderVals;
int unitsVals;
double unitCostVals;

int i, j, k;

//FUNCTION PROTOTYPES

void openFile (void);
void readFileLines (void);
void printFileData (FILE * fName, char fileName [], prodCost * pro_num);

double orderCost (FILE * fName, char fileName [], prodCost * pro_num);
double totalOrderCost (FILE * fName, char fileName [], prodCost * pro_num);

//START OF PROGRAM

int main (int argc, char * argv [ ])
{
    //get the file name
	openFile ();
	readFileLines ();
	printFileData (fName, fileName, prod);


	return (0);
}

void openFile (void)
{
	FILE_NAME:

	printf ("\nPlease enter the file name >> ");
    scanf ("%s", fileName);
    fName = fopen (fileName, "r");
    //check that the file exists in the user-given directory
    if (fName == NULL)
	{
		printf ("\nThis is not a valid file. Please enter a valid file in the directory.\n\n");
		goto FILE_NAME;
	}
    fclose (fName);

}
void readFileLines (void)
{
    fName = fopen (fileName, "r");

    //count lines starting here

    while (lines != EOF)
	{
        lines = getc (fName);
        if (lines == '\n')
		{
			++count;
			if (lines == EOF)
			{
				break;
			}
		}
	}
    size = count;

    prod = (int *) calloc (size, sizeof (int));

    free(prod);

    fclose (fName);
}

void printFileData (FILE * fName, char fileName [], prodCost * pro_num)
{
    fName = fopen (fileName, "r");
    prod = (int *) calloc (size, sizeof (int));

    for (i = 0; i < prod; i++)
	{
        fscanf ("%d\n", &prod);
        prod [i] = prods;
        printf ("%d.\tProducts : %d\n", (i + 1), prod [i]);
	}

    free(prod);
    fclose (fName);
}

double orderCost (FILE * fName, char fileName [], prodCost * pro_num)
{

}
double totalOrderCost (FILE * fName, char fileName [], prodCost * pro_num)
{

}

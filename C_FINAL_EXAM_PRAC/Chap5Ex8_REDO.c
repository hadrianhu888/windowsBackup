/******************************************************

XINYU HADRIAN HU
29/04/2018
C PROGRAM TO READ A LIST OF ORDERS FROM A FILE
CALCULATE TOTAL SUM OF EACH ORDER
AND TOTAL SUM OF ALL THE ORDERS IN THE FILE

******************************************************/

//PREPROCESSORS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

//MACROS

#define STR_MAX 50

//GLOBAL STRUCTURES

struct itemDetails
{
	long long int items;
	float unit_cost;
};


struct products
{
	long long int number_products;

	struct itemDetails item_info;

	float order_cost;
	float total_order_cost;
} * ptr_item_array;
//GLOBAL VARIABLES

FILE * ptrFile;
char fileName [STR_MAX];

int i, j, k;

char line_index;
int count = 0;
int size;

//GLOBAL FUNCTIONS

/*get file name*/
void getFileName (void);

/*read file lines*/
void readFileLines (FILE * ptr);

/*print file data*/
void printFileData (FILE * ptr, int size);

//START OF THE PROGRAM

int main (int argc, char * argv [ ])
{
	getFileName ( );
	readFileLines (ptrFile);
	printFileData (ptrFile, size);
	return (0);
}

//FUNCTION DEFINITIONS HERE

/***********************************************************************************************************************/

/*get file name*/
void getFileName (void)
{
    //get the name of the file here

    FILE:

    printf ("\nPlease enter the name of your file >> ");
    scanf ("%s", fileName);
    ptrFile = fopen (fileName, "r+");

    //check that the file exists

    if (ptrFile == NULL)
	{
		printf ("\nThe file does not exist. Please enter a file name again. >> ");
		goto FILE;
	}
    else if (ptrFile != NULL)
	{
		printf ("\nThe file %s exists.\n\n", fileName);
	}
    fclose (ptrFile);
}

/*read file lines*/
void readFileLines (FILE * ptr)
{
	ptrFile = fopen (fileName, "r+");

    //determine how the lines are to be counted here

    for (line_index = getc (ptrFile); line_index != EOF; line_index = getc (ptrFile))
	{
		if (line_index == '\n');
		{
			++count;
		}
	}
	size = count;

	ptr_item_array = (struct products *) calloc (size, sizeof (struct products));

	//check that there is enough memory in the heap

	if (ptr_item_array == NULL)
	{
		printf ("NOT ENOUGH MEMORY!\n\n");
		exit (1);
	}

	free(ptr_item_array);

	fclose (ptrFile);
}

/*print file data*/
void printFileData (FILE * ptr, int size)
{
    ptrFile = fopen (fileName, "r+");
	ptr_item_array = (struct products *) calloc (size, sizeof (struct products));

    for (i = 0; i < size; ++i)
	{
		fscanf (ptrFile, "%llu.\t", &ptr_item_array->number_products);
		for (j = 0; j < ptr_item_array->number_products; ++j)
		{
			fscanf ("%llu %f", &ptr_item_array->item_info.items, &ptr_item_array->item_info.unit_cost);
		}
	}

	free (ptr_item_array);
    fclose (ptrFile);
}







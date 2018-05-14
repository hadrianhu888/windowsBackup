/*************************************************************************************************

XINYU HADRIAN HU
28/04/2018
C PROGRAM TO ACCEPT TEMPERATURES OF A CITY FROM -50 TO +50 DEG CELSIUS
ALSO DISPLAY HOTTEST AND COLDEST TEMPERATURES FOR A CITY

*************************************************************************************************/

//PREPROCESSORS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//MACROS

#define EOL -99
#define MAX 50
#define MIN -50

#define FILE_STRING 50
#define ARR_MAX 500

//FUNCTION PROTOTYPES

void swap (int * x, int * y);
double maxTemp (double tData [ARR_MAX], int size);
double minTemp (double tData [ARR_MAX], int size);

//START OF THE PROGRAM

int main (int argc, char * argv [ ])
{
	//initialize local variables

	int i = 0, j, k;

    double temperature;
    double * tempArr;
    char city [FILE_STRING];
    double tArr [ARR_MAX];

    int counter = 0;
    int size;
    double temp_t;

    double hottest, coldest;

	//get user input

	printf ("\nEnter the name of the city >> ");
	fgets (city, FILE_STRING, stdin);
	printf ("\nYour City >> %s\n\n", city);

    do
	{
		T_INPUT:

		printf ("\nEnter a temperature for %s >> ", city);
        scanf ("%lf", &temperature);

        /***************************************************************

        Use continue to get out of this do while loop once the
        temperature is written as -99 and
        exit this loop and keep going to
        print out the data entered by the user

        ***************************************************************/

		if (temperature == EOL)
		{
			continue;
		}

        if (temperature > MAX || temperature < MIN)
		{
			printf ("\nTemperature must be between -50 deg C and +50 deg C.\n");
			goto T_INPUT;
		}
		//store the temperature records in an array by incrementing the counter and incrementing i accordingly

		printf ("\nTemperature >> %.3lf.\n", temperature);
		++counter;
		temp_t = temperature;
		tArr [i] = temperature;
		++i;

	} while (temperature != EOL);

	//print out the results here by using temporary arrays to iterate back to the pointer array via calloc
	PRINT_RESULTS:

	size = counter;

	tempArr = (double * ) calloc (size, sizeof (double));

	if (tempArr == NULL)
	{
		printf ("\nNOT ENOUGH MEMORY!\n\n");
		exit (1);
	}

	printf ("\nRecords of Temperatures in %s >> \n\n", city);

	for(j = 0; j < size; j++)
	{
        tempArr [j] = tArr [i];
        printf ("%d.\t%.3lf\n", (j + 1), tArr [j]);
	}

	//print out the hottest and coldest temperatures here

	hottest = maxTemp (tArr, size);
	coldest = minTemp (tArr, size);

	free(tempArr);

	return (0);
}
/**

FUNCTION DEFINITIONS

**/

//swaps two numbers
void swap (int * x, int * y)
{
	int temp;

	temp = * x;
	* x = * y;
	* y = temp;
}

// function to calculate the maximum temperature
double maxTemp (double tData [ARR_MAX], int size)
{
    double max = 0;
    int i, j, k;
    for (i = 0; i < size; ++i)
	{
		if (max < tData [i])
		{
			max = tData [i];
		}
	}
	printf ("\nMax Temperature >> %.3lf deg C.\n\n", max);
	return (max);
}

// function to calculate minimum temperature
double minTemp (double tData [ARR_MAX], int size)
{
	double min = 0;
	int i, j, k;
	for (i = 0; i < size; ++i)
	{
		if (min > tData [i])
		{
			min = tData [i];
		}
	}
	printf ("\nMin Temperature >> %.3lf deg C.\n\n", min);
	return (min);
}


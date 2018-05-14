/******************************************************************************
XINYU HADRIAN HU
500194233
CPS 125
RYERSON UNIVERSITY
ASSIGNMENT 7
TENFOLD TAKE-HOME ASSIGNMENT
*******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//including preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//defining MACROS

#define PI 3.14159
#define TRUE 1
#define FALSE 0

//define functions

double tenfold (double arr[], int size)
{
    int i, j;
    double array_ten_fold[size];

    printf("\n-----------------------------------------\nTenfold Output Results\n-----------------------------------------\n");

    for(i = 0; i < size; ++i)
	{
		if(arr[i] > 0)
		{
			array_ten_fold[j] = arr[i] * 10;
			printf("\n%d of %d >> %.3lf", (i + 1), size, array_ten_fold[j]);
		}
		else if (arr[i] <= 0)
		{
			array_ten_fold[j] = arr[i] * 1;
			printf("\n%d of %d >> %.3lf", (i + 1), size, array_ten_fold[j]);
		}
	}

	return array_ten_fold[j];
}

int main (int argc, char *argv[])
{

    //declaring variables

    int size;
    double input [size];
    int i;
    double *vector;
    double ten_fold;

    vector = malloc (size* sizeof (int*));

	//user input

	printf("Enter Size of the array >> ");
	scanf("%d", &size);
	printf("\nSize >> %d\n", size);

	//print out the array

	for(i = 0; i < size; ++i)
	{
		printf("\nEnter %d of %d >> ", (i + 1), size);
		scanf("%lf", &input[i]);
		printf("\n%d of %d >> %.3lf\n", (i + 1), i, input [i]);
	}

	printf("\n\n-----------------------------------------\nUser Input >>\n-----------------------------------------\n");

	for(i = 0; i < size; ++i)
	{
		printf("\n%d of %d >> %.3lf", (i + 1), size, input [i]);
	}

	free(vector);

	//output the array

	ten_fold = tenfold (input, size);

return (0);
}





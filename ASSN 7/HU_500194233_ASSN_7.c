/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

CPS 125 Assignment 7 Base Code prior to Reading from File section
XINYU HADRIAN HU
500194233
14/02/2018
CPS 125
RYERSON UNIVERSITY
More loops - for loops examples
This program forms the basis for the normalization assignment for Lab 7. The code here will be extrapolated to read from file
- STILL NEED TO DETERMINE HOW TO USE WHILE LOOP TO READ FROM FILE AND INPUT VALUES INTO ARRAY
Many functions will be implemented once the foundations of the current code works as intended - PROBLEM SOLVED

*/

//including preprocessor directives

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//defining essential MACROS

#define PI 3.14159
#define SPACE printf("\n");
#define FALSE 0
#define TRUE 1
#define PHI 0.618
#define POWER 2

//define necessary functions

double array_sum (double arr[], int size);	            //calculates sum of array values
double array_avg (double arr[], int size);          	//calculates average of the array values
double array_max (double arr[], int size);	            //calculates max value in the array
double array_min (double arr[], int size);	            //calculates min value in the array
double array_norm (double arr[], int size);	            //normalizes the given array
double array_variance (double arr[], int size);         //calculate the variance of the array
double array_std_dev (double arr[], int size);          //calculates the standard deviation of the array
int array_freq (double arr[], int size);                //calculates the frequency of every value in the array to check for all duplicates
double array_diff (double arr[], int size);             //calculates the difference between array[i] and array[j]
                                                        //values and see if they are equal to zero, if they are - add to counter
/*

---------------------------------------------------------------------------------------------------------------

*/

int
main (int argc, char *argv[])
{

    //declare initial variables

    int i, j;

    //declare variables related to array

    int size;
    double array[size];

    //declare temp variable to store size of array for later use

    int temp;
    double *vector;

    //declare values to calculate and then print

    double sum, avg, max, min, norm, var, std_dev;

    //allocate memory for array

    vector = malloc (size * sizeof (double *));

    //user input
    SPACE;
    printf("Normalization Calculator with User-Defined Dynamic Array\n");
    printf("-----------------------------------------------------------");
    SPACE;
    printf ("Enter the size of the desired array >> ");
    scanf ("%d", &size);
    SPACE;
    printf ("Size of Array >> %d.", size);
    printf("\n-----------------------------------------------------------");
    SPACE;

  //input each number in the array

    for (i = 0; i < size; ++i)
        {
        printf ("\nEnter value %d of %d >> ", (i + 1), size);
        scanf ("%lf", &array[i]);
        printf ("\nValue %d of %d >> %.3lf.\n", (i + 1), size, array[i]);
        }

  //print all values at once in a list, vertically

        temp = size;
        size = temp;
        //printf ("\nTemp Value >> %d.\n", temp);
        printf("-----------------------------------------------------------");
        printf ("\nValues in User-Defined Array\n");
        printf("-----------------------------------------------------------");
        SPACE;

  /*
     --------------------------------------------------------------------------------------
     This code just prints out zero, so the array is not being remembered -
     attempts to reset array size creates an error output of 0.000 at where the actual value is supposed to be.
     For example
     Enter array size >> 1
     Array size 1
     1 of 1 >> 1
     You entered 1.
     Values in user defined array
     Value 1 of 1 >> 0.000
     (on the iPad compiler)

     PROBLEM SOLVED - via online COMPILER

     https://www.onlinegdb.com/online_c_compiler
     --------------------------------------------------------------------------------------

   */

    //prints out the values of the array

    for (i = 0; i < size; ++i)
        {
        printf ("Value %d of %d >> %.3lf.\n", (i + 1), size, array[i]);
        }
    //check for duplicates here

    int duplicates;
    duplicates = array_diff(array, size);
    if (duplicates == size)
    {
        printf("\n\nERROR! VALUES IN THE ARRAY CANNOT ALL BE THE SAME VALUE!\n\n");
    }
    //free the vector from memory allocation

     //free (vector);

     //prints out the results by calling appropriate functions
    else if (duplicates != size)
    {
     printf("-----------------------------------------------------------\n");
     printf ("\nCalculated Results >>\n");
     printf("-----------------------------------------------------------");
     SPACE;

     /*
    --------------------------------------------------------------------------------------
    TODO:

    Figure out why sum is being printed out twice - PROBLEM SOLVED
    and
    why minimum value in array is 0 in the online C compiler - PROBLEM SOLVED
    --------------------------------------------------------------------------------------

     */

    sum = array_sum (array, size);
    avg = array_avg (array, size);

    max = array_max (array, size);
    min = array_min (array, size);

    var = array_variance (array, size);
    std_dev = array_std_dev (array, size);

    //print results here
    printf("Sum >> %.3lf", sum);
    SPACE;
    printf("Average >> %.3lf", avg);
    SPACE;
    printf("Min >> %.3lf", min);
    SPACE;
    printf("Max >> %.3lf", max);
    SPACE;
    printf("Variance >> %.3lf", var);
    SPACE;
    printf("Standard Deviation >> %.3lf", std_dev);
    SPACE;
    printf("-----------------------------------------------------------");
    SPACE;
    array_norm (array, size);

    }

  return (0);
}

/*
-------------------------------------------------------------------------------
From this point onward, the functions are being defined and calculated
-------------------------------------------------------------------------------
*/

double
array_sum (double arr[], int size)
{

    //calculates sum of array values

    int i;
    double sum = 0;

    //use for loop to determine sum of the numbers

    for (i = 0; i <= size; ++i)
        {

            sum += arr[i];

        }

    //printf ("\nSum = %.3lf.\n", sum);

    return (sum);

}

double
array_avg (double arr[], int size)
{

  //calculates average of the array values

    int i;
    double average;
    double sum_array;

    sum_array = array_sum (arr, size);

  //calculates the average value

    average = sum_array / size;

        //printf ("Average = %.3lf.\n", average);

    return (average);

}

double
array_max (double arr[], int size)
{

  //calculates max value in the array

    int i;
    double max = arr[0];

    for (i = 0; i <= size; ++i)
    {

        if (arr[i] > max)
	    {

	        max = arr[i];

	    }

    }

    //printf ("Max = %.3lf.\n", max);

    return (max);

}

double
array_min (double arr[], int size)
{

  //calculates min value in the array

    int i;
    double min = arr[0];

    for (i = 0; i < size; ++i)
    {

        if (arr[i] < min)

        /*

        for min, set the array to be LESS than but NOT EQUAl to min value of the array,
        otherwise it will go on to the next empty container of the array

        */

        {

	        min = arr[i];

	    }

    }

    //printf ("Min = %.3lf.\n", min);

    return (min);

}

double
array_norm (double arr[], int size)
{

  //normalizes the given array

    int i;
    double norm[size];
    double max, min;
    double diff;

    max = array_max (arr, size);
    min = array_min (arr, size);
    diff = max - min;

  for (i = 0; i <= size; ++i)
    {

       norm[i] = (arr[i] - min) / diff;

    }

    //print out the results
    printf("-----------------------------------------------------------");
    SPACE;
    printf("\nNormalized Array >> \n");
    printf("-----------------------------------------------------------");
    SPACE;

    int duplicates;
    duplicates = array_diff(arr, size);
    if (duplicates == size)
    {
        for(i = 0; i < size; ++i)
        {
        printf("Normalized Value %d of %d >> ERROR\n", (i + 1), size);
        }
    }
    else if (duplicates != size)
    {
       for(i = 0; i < size; ++i)
        {
        printf("Normalized Value %d of %d >> %.3lf\n", (i + 1), size, norm[i]);
        }

    }

}

double array_variance (double arr[], int size)
{

    //calculate the variance of the array

    int i;
    double arr_var;
    double mean;

    //calculate the mean

    mean = array_avg(arr, size);

    for(i = 0; i <= size; ++i)
    {
        arr_var += pow((arr[i] - mean), POWER) / size;
    }

    //printf("Variance = %.6lf.\n", arr_var);

    return (arr_var);

}

double array_std_dev (double arr[], int size)
{

    //calculate the standard deviation of the array

    double arr_var = array_variance(arr, size);
    double arr_std_dev;
    arr_std_dev = sqrt(arr_var);

    //printf("Standard Deviation = %.6lf.\n", arr_std_dev);

    return (arr_std_dev);

}

int
array_freq (double arr[], int size)

    //count frequency of a certain value in the array
{
    int i, j, count;
    int freq[size];

    for(i = 0; i < size + 1; ++i)
    {
         count = 1;
         for (j = i + 1; j < size; ++j)
         {
              //check if there is at least one duplicate
              if (arr[i] == arr[j])
              {
                  ++count;
                  freq[j] = 0;
              }
              //check if frequency of i is not zero

         }
        if (freq[i] != 0)
        {
            //update the frequency counter
            freq[i] = count;
        }
    }
    return (count);
}

double array_diff (double arr[], int size)
{
    /*
    This function checks if array[i] - array[j] == 0 and if it does, add it to the counter
    */

    int i, j, count;
    int freq[size];

    for(i = 0; i <= size; ++i)
    {
        count = 1;
        for (j = i + 1; j < size + 1; ++j)
        {
            if (arr[i] - arr[j] == 0)
            {
                ++count;
                freq[j] = 0;
            }
            else if (arr[i] - arr[j] != 0)
            {
                freq[i] = count;
            }
        }

        freq[i] = count;
    }
}

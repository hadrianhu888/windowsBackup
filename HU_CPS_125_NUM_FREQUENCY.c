
//including preprocessor directives
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//defining MACROs
#define PI 3.14159
#define MAX 5000

int main (int argc, char *argv[])
{

    //declaring variables

    FILE *data;

    //opening and reading the file
    data = fopen ("water.dat", "r+");

	int i, j, size = 0;
    double monthly_water_array[size];
    double status_water_data;
    char space = ' ';
    int counter;

    status_water_data = fscanf(data, "%lf ", &monthly_water_array[i]);

    while (status_water_data != EOF)
    {
    	fscanf(data, "%lf ", &monthly_water_array[i]);
		size += i;

    } fscanf(data, "%lf ", &monthly_water_array[i]);

    printf("Data >> %lf\n", size);



	//closing the file
    fclose(data);

	return (0);
}

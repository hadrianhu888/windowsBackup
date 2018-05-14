/*
XINYU HADRIAN HU
500194233
10022018
RYERSON UNIVERSITY
PROGRAM TO MINIMIZE COST TRANSPORTING
LOADS FROM AN AIRPORT USING 2 TRUCKS
*/

//including preprocessor directives

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//defining MACROs

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define SPACE printf("\n");
#define DIVISOR 2

//define necessary functions

/*
MAKE THIS PROGRAM MODULAR
TODO
Function to find maximum and minimum cost/trip
Function to find maximum and minimum load
Function to determine minimum cost given an arbitrary tonnage to transport
*/

float max_min_cost(float c1, float c2, float *min_c, float *max_c);

double max_min_load (double w1, double w2, double *min_l, double *max_l);

long double optimal_min_cost(long double tons, float c_1, float c_2, int load_1, int load_2, int *trip_1, int *trip_2, float *min_cost_optimal);

int main (int argc, char *argv[]) {

    //declare initial variables to input

    long double tonnage;

    //loads, costs and trips to be determined

    int load1, load2;
    float cost1, cost2;
    int trip1, trip2;
    long double min_total_cost;

    float *min_cost, *max_cost;
    float *min_load, *max_load;
    float high_low_cost;
    float high_low_load;

    //input variables

    SPACE;
    printf("Enter total tonnage>> ");
    scanf("%Lf", &tonnage);
    SPACE;
    printf("Enter load 1 capacity of truck 1>> ");
    scanf("%d", &load1);
    SPACE;
    printf("Enter load 2 capacity of truck 2>> ");
    scanf("%d", &load2);
    SPACE;
    printf("Enter cost per trip capacity of truck 1>> ");
    scanf("%f", &cost1);
    SPACE;
    printf("Enter cost per trip capacity of truck 2>> ");
    scanf("%f", &cost2);
    SPACE;

    //output what the user entered

    printf("Total Tonnage>> %.3Lf tonnes.\n\n", tonnage);
    printf("Truck 1 Load Per Trip>> %d tonnes.\n\n", load1);
    printf("Truck 2 Load Per Trip>> %d tonnes.\n\n", load2);
    printf("Truck 1 Cost Per Trip>> $%.2f per trip.\n\n", cost1);
    printf("Truck 2 Cost Per Trip>> $%.2f per trip.\n\n", cost2);

    //check the given conditions by using the functions

    high_low_cost = max_min_cost(cost1, cost2, &min_cost, &max_cost);

return (0);
}

float max_min_cost(float c1, float c2, float *min_c, float *max_c) {

    //check cost1 against cost2

    if (c1 < c2) {
        min_c = &c1;
        max_c = &c2;

        printf("Truck 1 Min Cost >> $%.2f.\nTruck 2 Max Cost >> $%.2f.\n", &min_c, &max_c);
    }

    //otherwise

    else if (c1 > c2) {
        min_c = &c2;
        max_c = &c1;

        printf("Truck 2 Min Cost >> $%.2f.\nTruck 1 Max Cost >> $%.2f.\n", &min_c, &max_c);
    }

}

double max_min_load (double w1, double w2, double *min_l, double *max_l){

    //check load1 against load2

    if (w1 < w2) {
        min_l = &w1;
        max_l = &w2;
    }

    //otherwise

    else if (w1 > w2) {
        min_l = &w2;
        max_l = &w1;
    }

}

long double optimal_min_cost(long double tons, float c_1, float c_2, int load_1, int load_2, int *trip_1, int *trip_2, float *min_cost_optimal) {



}

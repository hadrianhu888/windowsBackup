
/*
XINYU HADRIAN HU
500194233
10022018
RYERSON UNIVERSTIY
CPS 125
-------------------------------------------------------------
PROGRAM TO DETERMINE 6-SPEED
GEAR BOX RATIO
BETWEEN MAX AND MIN
SPEEDS
-------------------------------------------------------------
*/

//preprocessor directives

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//defining necessary MACROs

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define SPACE printf("\n\n");
#define DIV 0.20

//defining necessary functions

float ratio_max_min (double max, double min);

double swap (double *max, double *min);

int main (int argc, char *argv[]) {

    //defining variables

    double maximum, minimum;
    float ratio_max_min_result;

    //input values

    SPACE;
    printf("Enter maximum speed in RPM>> ");
    scanf("%lf", &maximum);
    SPACE;
    printf("Enter minimum speed in RPM>> ");
    scanf("%lf", &minimum);

    /*
    Show what the user entered
    Swap the values if need be to show the correct high and low speeds
    */
    if (maximum < minimum) {
        swap(&maximum, &minimum);
    }

    SPACE;
    printf("MAX >> %.3lf RPM.\n\nMIN >> %.3lf RPM.", maximum, minimum);

    //output

    ratio_max_min_result = ratio_max_min (maximum, minimum);


return (0);
}

//this function returns the desired gear-box ratio value

float ratio_max_min (double max, double min) {

    //defining ratio return variable

    float ratio;
    //calculate the result from the given parameters

    ratio = pow(((float)max/min), DIV);

    //function output

    SPACE;
    printf("The ratio between successive speeds of a six-speed gear box\nwhen the maximum speed is %.3lf RPM\nand when the minimum speed is %.3lf RPM,\nthe gear ratio is %.3f.\n\n", max, min, ratio);

    //end of function

    return (ratio);
}
//this function can reverse the two numbers if the user accidentally enter the smallest in the biggest and the biggest in the smallest

double swap (double *max, double *min) {

    //use call by reference

    int temp;

    //use temp to temporarily store each value and then release them into the correct pointer addresses

    temp = *min;
    *min = *max;
    *max = temp;

}


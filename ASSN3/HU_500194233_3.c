#include <stdio.h>
#include <math.h>
#include <string.h>

//common defined preprocessor directives

#define PI 3.14159
#define SPACE printf("\n\n");

//part 2

#define MY 1.094
#define MMI 0.0006215

/*
Xinyu Hadrian Hu
500194233
Assignment 3
CPS 125
14/01/2018
*/

int main (void){

    //part 1
    //program to add, subtract, divide, and multiply four numbers
    //initializing variables

    int num1, num2, num3, num4;

    int sum0, sum1, diff;

    double prod, quot, sum_square, sum_sqrt, sum_sqrt_quot;

    //let the user enter the four numbers;

    printf("\n-----------Part 1: Calculator to find averages of four numbers-----------\n");

    printf("\nEnter the 1st number: ");
    scanf("%d",&num1);
    printf("\nEnter the 2nd number: ");
    scanf("%d", &num2);
    printf("\nEnter the 3rd number: ");
    scanf("%d", &num3);
    printf("\nEnter the 4th number: ");
    scanf("%d", &num4);

    printf("\n\n1. The four numbers you entered are: %d, %d, %d, and %d.", num1, num2, num3, num4);

    //calculate the sum of the four numbers

    sum0 = num1 + num2 + num3 + num4;

    printf("\n\n2. The sum of the four numbers is: %d.", sum0);

    //calculate the difference between num1 + num2 and num3 + num4

    sum1 = (num1 + num2) - (num3 + num4);

    printf("\n\n3. The difference of the sum between the first + second, and third + fourth is: %d", sum1);

    //calculate the sum of the squares of the four numbers entered by the user

    sum_square = (double) (pow(num1, 2) + pow(num2, 2) + pow(num3, 2) + pow(num4, 2));

    sum_sqrt = sqrt(sum_square);

    printf("\n\n4. The sum of the squares of the four numbers is: %.2lf", sum_square);

    printf("\n\n5. The square root of (4) is: %.2lf.", sum_sqrt);

    //calculate the exact quotient of sum_square/sum

    sum_sqrt_quot = sum_sqrt / (double) (sum0);

    //prints out the final result

    printf("\n\n6. The exact quotient between (5) and (2) is: %.2lf.", sum_sqrt_quot);

    SPACE;

    /*---------------------------------------------END OF PROGRAM-------------------------------------*/

    //part 2
    /*program to convert meters to yards and miles by having the user enter the distances in meters first*/

    //declare variables for meters

    double d1, d2, d3, d4;

    //declare variables for yards

    double d1y, d2y, d3y, d4y;

    //declare variables for miles

    double d1mi, d2mi, d3mi, d4mi;

    printf("\n---------------Distance Conversion Calculator---------------\n");

    //input vales

    printf("\n\nEnter distance 1: ");
    scanf("%lf", &d1);
    printf("\n\nEnter distance 2: ");
    scanf("%lf", &d2);
    printf("\n\nEnter distance 3: ");
    scanf("%lf", &d3);
    printf("\n\nEnter distance 4: ");
    scanf("%lf", &d4);

    //displays input values

    printf("\n\nThe four distances you entered are: %.2lf m, %.2lf m, %.2lf m, and %.2lf m.", d1, d2, d3, d4);

    //convert meters to yards

    d1y = d1 * MY;
    d2y = d2 * MY;
    d3y = d3 * MY;
    d4y = d4 * MY;

    //convert meters to miles

    d1mi = d1 * MMI;
    d2mi = d2 * MMI;
    d3mi = d3 * MMI;
    d4mi = d4 * MMI;

    //display the results in a table

    SPACE;

    printf("Meters\t\tYards\t\tMiles\n\n");

    printf("%.2lf m\t%.2lf yd\t%.6lf mi\n", d1, d1y, d1mi);
    printf("%.2lf m\t%.2lf yd\t%.6lf mi\n", d2, d2y, d2mi);
    printf("%.2lf m\t%.2lf yd\t%.6lf mi\n", d3, d3y, d3mi);
    printf("%.2lf m\t%.2lf yd\t%.6lf mi\n", d4, d4y, d4mi);

    /*---------------------------------------------END OF PROGRAM-------------------------------------*/

    //part3

    /*
    The difference between the division (/) and the remainder or mod operator (%) is that the former
    provides a double value while the latter gives an integer value as the answer when two numbers
    divide.
    */

return (0);
}

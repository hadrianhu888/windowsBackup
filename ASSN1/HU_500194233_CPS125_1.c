#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.14159

int main (void) {

//Xinyu Hadrian Hu
//500194233
//First C Program

//Part 1.1

printf("\nThis is my first C program.\n");

//Part 1.2

printf("\nThis\nis\nmy\nsecond\n\C\nprogram.\n");

//Part 2

printf("\nx o x\nx x o\no o x\n");

//Part 3

//printf prints out a value entered by the user using scanf.

double rad, A;

printf("Enter the radius of the circle: ");

//use enters radius

scanf("%lf", &rad);

//calculate area of the circle

A = PI * pow(rad, 2);

//prints out the result

printf("\nThe area of the cirlce is %.3lf unit squared.", A);

return (0);
}

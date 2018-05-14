/*
XINYU HADRIAN HU
RYERSON UNIVERSITY
500194233
10022018
C PROGRAM TO FIND LARGEST AND SMALLEST OF THREE NUMBERS BY FUNCTION
*/

//preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//defining MACROS

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define SPACE printf("\n\n");

//defining needed functions

int largest_3(int t1, int t2, int t3);
int smallest_3(int s1, int s2, int s3);

//main function is here

int main (int argc, char *argv[]) {

    //declaring variables
    int n1, n2, n3;
    int max, min;

    //input
    SPACE;
    printf("Enter three numbers>> ");
    SPACE;
    printf("Enter your first value>> ");
    scanf("%d", &n1);
    SPACE;
    printf("Enter your second value>> ");
    scanf("%d", &n2);
    SPACE;
    printf("Enter your third value>> ");
    scanf("%d", &n3);
    SPACE;

    //output
    printf("You entered: %d, %d, and %d.", n1, n2, n3);
    SPACE;

    //call the functions

    max = largest_3 (n1, n2, n3);
    min = smallest_3 (n1, n2, n3);


return (0);
}

//functions are here

//function to find the largest of three numbers

int largest_3(int t1, int t2, int t3) {

    //declare result variable
    int largest;

    //check if t1 is the largest
    if (t1 > t2 && t2 > t3) {
        largest = t1;
        SPACE;
        printf("Largest value>> %d", t1);
        SPACE;
    }

    //check if t2 is the largest
    else
        if (t2 > t1 && t1 > t3) {
            largest = t2;
            SPACE;
            printf("Largest value>> %d", t2);
            SPACE;
        }
    //otherwise, t3 is the largest
    else {
        largest = t3;
        SPACE;
        printf("Largest value>> %d", t3);
        SPACE;
        }

    return largest;
}

//function to find the smallest of three numbers

int smallest_3(int s1, int s2, int s3) {

    //declare result variable
    int smallest;

    //check if s1 is the smallest
    if (s1 < s2 && s2 < s3) {
        smallest = s1;
        SPACE;
        printf("Smallest value>> %d", s1);
        SPACE;
    }

    //check if s2 is the smallest
    else
        if (s2 < s1 && s1 < s3) {
            smallest = s2;
            SPACE;
            printf("Smallest value>> %d", s2);
            SPACE;
        }
    //otherwise, s3 is the smallest
    else {
        smallest = s3;
        SPACE;
        printf("Smallest value>> %d", s3);
        SPACE;
        }

    return smallest;
}



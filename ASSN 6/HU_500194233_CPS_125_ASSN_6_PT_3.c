/*
XINYU HADRIANH HU
RYERSON UNIVERSITY
500194233
10022018
CPS 125
---------------------------------------------------
C PROGRAM TO FIND THE REMAINDER OF
NUMBERS BY USING USER DEFINED FUNCTION
WITH MULTIPLE RETURNING RESULTS
---------------------------------------------------
*/

//preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//defining MACROs

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define SPACE printf("\n\n");
#define DIVISOR 10

//defining necessary functions

int output(int x, int *tens, int *rem, int *input);

//this is the main function
int main (int argc, char *argv []) {

    //declare user input variable

    int num, *ten, *mod, *user_num;

    //input

    SPACE;
    printf("Enter your number>> ");
    scanf("%d", &num);

    //output user-defined number via call by function

    int user_io;
    user_io = output(num, &ten, &mod, &user_num);

    //end the program

return (0);
}

//defining the meaning of the user-defined function
int output(int x, int *tens, int *rem, int *input) {

    //declare desired return output value

    int output;

    //calculate the values needed

    tens = x / DIVISOR;
    rem = x % DIVISOR;
    input = x;

    //print out the results in the function itself

    printf("\nTENS >> %d", tens);
    printf("\nONES >> %d", rem);
    printf("\nINPUT >> %d\n", x);

return (output);
}

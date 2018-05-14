/*
XINYU HADRIANH HU
RYERSON UNIVERSITY
500194233
10022018
CPS 125
C PROGRAM TO FIND THE REMAINDER OF
NUMBERS BY USING FUNCTIONS
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

//defining necassary functions

int ret_10 (int x);
int ret_rem (int y);
void ptr_user_value (int *input);

int main (int argc, char *argv[]) {

    //declare variables

    //part 1

    int num;

    //----------------------------------------

    //input
    SPACE;
    printf("Enter a number>> ");
    scanf("%d", &num);
    SPACE;

    //output
    printf("You entered>> %d", num);
    SPACE;

    //part 2

    //using a do...while loop

    do {

        printf("\n\nEnter a number>> ");
        scanf("%d", &num);
        SPACE;

    } while (num > 10 && num <= 99);

    //using a for loop instead

    for(num==10; num <= 99; ++num) {

        printf("\n\nEnter a number>> ");
        scanf("%d", &num);

    }

    /*
    The do...while loop is certainly easier due to its ability to terminate once the condition required is not true
    -----------------------------------------------------------------------------------------------------------------
    The for loop requires knowing the limits and the increments available
    */

    //part 3

    int user_num;

    //----------------------------------------

    SPACE;
    printf("Enter a number>> ");
    scanf("%d", &user_num);
    SPACE;

    //calculating 10s

    printf("The tens value is>> %d.", user_num/10);
    SPACE;

    //part 4 - calculating remainder

    printf("The remainder is>> %d.", user_num%10);
    SPACE;

    //part 5 and 6 output

    int user_input;
    int tens, remainder;

    //----------------------------------------

    printf("Enter a number>> ");
    scanf("%d", &user_input);

    //output from functions

    tens = ret_10 (user_input);
    remainder = ret_rem (user_input);

    SPACE;
    printf ("You entered>. %d.", user_input);
    SPACE;

return (0);
}

//this function returns 10s
int ret_10 (int x) {

    //defining variables

    int tens;

    //calculating the tens

    tens = x / DIVISOR;

    //output

    SPACE;
    printf("TENS >> %d", tens);
    SPACE;

    return (tens);
}

//this function returns remainders
int ret_rem (int y) {

    //declaring return values

    int rem;

    //calculating the remainder

    rem = y % DIVISOR;

    //output

    printf("REMAINDER >> %d", rem);
    SPACE;

    return (rem);
}

void ptr_user_value (int *input) {

    int *address;

    //pointer points to address of user input value

    address = &input;
    printf("The number you entered is >> %d", *address);

    return (&address);
}


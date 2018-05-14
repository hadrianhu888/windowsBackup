#include <stdio.h>
#include <math.h>

#define PI 3.1416
#define SPACE printf("\n\n");

//C program to reverse a number by using an array

int main (int argc, char *argv[]) {

    int n;
    int count = 0;


    printf("\n\nEnter an integer>> ");
    scanf("%d", &n);

    int reversedNumber = 0, remainder;

    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
        count++;
    }

    printf("\n\nReversed Number = %d", reversedNumber);

    printf("\n");

    printf("\n\nNumber of digits: %d\n\n", count);

    if(reversedNumber == n)
        printf("\n\nYour number is a palindrome.");





return(0);

}

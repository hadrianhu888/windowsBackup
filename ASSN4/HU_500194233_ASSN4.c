/*

Setting up preprocessor directives
and defining preprocessor macros

*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.14159
#define SPACE ("/n/n");
#define T_A 4

/*
Xinyu Hadrian Hu
500194233
15/01/2018
CPS 125
Assignment 4
*/
int main (void){

    //declare variables

    //two assignments and two tests

    float a1, a2, t1, t2;

    //average grade

    float sum, avg;

    //grade point letter score

    char grade;

    //input values

    printf("\n\nTest and Assignment Score Calculator\n\n");

    printf("1. Enter the first assignment score: ");
    scanf("%f", &a1);
    printf("\n\n2. Enter the second assignment score: ");
    scanf("%f", &a2);
    printf("\n\n3. Enter the first test score: ");
    scanf("%f", &t1);
    printf("\n\n4. Enter the second test score: ");
    scanf("%f", &t2);

    //print out the grades in a table

    printf("\n\nYou entered the following scores: ");
    printf("\n\nAssignments\t\tTests\n\n");
    printf("Assn 1: %.2f%%\t\tTest 1: %.2f%%\n", a1, t1);
    printf("Assn 2: %.2f%%\t\tTest 2: %.2f%%\n\n", a2, t2);

    //calculate the sum of the four grades

    sum = a1 + a2 + t1 + t2;

    //calculate the average of the four scores

    avg = sum / T_A;

    //print out the average score

    printf("Your average score is: %.2f%%.", avg);

    //calculate letter grade based on numerical score

    /*        Letter grade scale

    80-100 A
    70-79 B
    60-69 C
    50-59 D
    < 50 F

    < 50 for either one or both assignments, then letter grade - 1
    < 50 for either one or both tests, then letter grade is F

    */

    if (avg >= 80 && avg <= 100) {
        grade = 'A';
    }
    else if (avg >= 70 && avg <= 79) {
        grade = 'B';
    }
    else if (avg >= 60 && avg <= 69) {
        grade = 'C';
    }
    else if (avg >= 50 && avg <= 59) {
        grade = 'D';
    }
    else if (avg < 50) {
        grade = 'F';
    }

    //now need to satisfy the other conditions of the marking scheme

    if ((t1 < 50 || t2 < 50) || (t1 < 50 && t2 < 50)) {
        grade = 'F';
    }
    else if ((a1 < 50 || a2 < 50) || (a1 < 50 && a2 < 50)) {
        --grade;
    }
    printf("\n\nYour letter grade is: \'%c\'.", grade);

    SPACE;

return (0);
}

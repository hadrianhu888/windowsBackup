#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.14159

int main (void) {

    //initialize variables

    float start, finish, diff;

    double rate, reimb;

    //let the user input values into the form

    printf("Enter the rate per mile: ");

    scanf("%lf", &rate);

    printf("\nEnter the starting distance in miles: ");

    scanf("%f", &start);

    printf("\nEnter the final distance in miles: ");

    scanf("%f", &finish);

    //calculate the reimbursement

    reimb = (double)(finish - start) * rate;

    printf("\n\nRate: $%.2lf", rate);
    printf("\nInitial: %.3f miles\nFinal: %.3f miles", start, finish);
    printf("\nDifference: %.2f miles", finish - start);
    printf("\nReimbursement: $%.2lf\n\n", reimb);


return (0);
}

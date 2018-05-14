//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//MACROS

#define ZERO 0.00
#define DISC100 100.00
#define DISC200 200.00
#define OVER100 -10.00
#define OVER200 -25.00

int main (int argc, char * argv [ ])
{
    //variables

    double total_cost;
    double after_discount;

    PRICE:

    //get user input

    printf ("\n\nEnter the total cost of the purchases >> ");
    scanf ("%lf", &total_cost);
    printf ("\n\nYou entered >> $%.2lf.\n\n", total_cost);

    //check which discount applies and print out the results

    if (total_cost >= DISC200)
	{
		after_discount = total_cost + OVER200;
		printf ("Total Cost after Over $200.00 Discount >> $%.2lf.\n\n", after_discount);
	}
	else if (total_cost >= DISC100 && total_cost < DISC200)
	{
		after_discount = total_cost + OVER100;
		printf ("Total Cost after Over $100.00 Discount >> $%.2lf.\n\n", after_discount);
	}
	else if (total_cost < DISC100 && total_cost > ZERO)
	{
		after_discount = total_cost;
		printf ("No Discounts Applied for Items Less than $100.00 >> $%.2lf.\n\n", after_discount);
	}
	else if (total_cost <= ZERO)
	{
		printf ("Invalid total cost. Please enter again.\n\n");
		goto PRICE;
	}

	return (0);
}

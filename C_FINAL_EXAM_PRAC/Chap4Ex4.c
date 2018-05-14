//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//MACROS

#define BOLT 0.05
#define NUT 0.02
#define WASH 0.01

int main (int argc, char * argv [ ])

{
    //declare variables

    int bolts, nuts, washers;
    double total_cost;

    //get user input for bolts, nuts and washers

    BOLTS_NUTS:

		printf ("\n\nEnter the number of bolts >> ");
		scanf ("%d", &bolts);

		printf ("\n\nEnter the number of nuts >> ");
		scanf ("%d", &nuts);

    //check that nuts and bolts are == to each other to qualify for a correct order, otherwise display a message to let the user enter again

	printf ("\n\nBolts >> %d\n\nNuts >> %d\n", bolts, nuts);

    if (bolts != nuts)
	{
		printf ("Invalid number of nuts and bolts. Please re-enter quantities of nuts and bolts.\n");
		goto BOLTS_NUTS;
	}
	else if (bolts == nuts)
	{
		goto WASH_Q;
	}

	WASH_Q:

		//get washer price

		printf ("\nEnter number of washers >> ");
		scanf ("%d", &washers);

		if (washers != 2 * bolts)
		{
			printf ("\nInvalid number of washers. Please re-enter number of washers.\n");
			goto WASH_Q;
		}
		else if ((washers >= 2 * bolts) && (washers >= 2 * nuts))
		{
			goto PRICE;
		}

		printf ("\n\nWashers >> %d\n", washers);

	PRICE:

		//find total price

        total_cost = (BOLT * bolts) + (NUT * nuts) + (WASH * washers);

        printf ("\n\nItems Ordered & Quantity\n");
        printf ("\nBolts\tNuts\tWashers\n");
        printf ("%d\t%d\t%d", bolts, nuts, washers);
        printf ("\n\nTotal Cost of the Order >> $%.2lf.\n\n", total_cost);

	return (0);
}

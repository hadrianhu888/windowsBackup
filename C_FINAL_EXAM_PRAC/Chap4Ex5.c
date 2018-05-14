//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//MACROS

#define ADULTREG 13.00
#define ADULTMAT 11.00

#define CHILDREG 7.00
#define CHILDMAT 2.00

#define ADULTDIS 2200
#define ADULT 14

#define TIMELIMIT 2200
#define PERCENT 0.01

#define CLOCK 2400

int main (int argc, char * argv [ ])
{
    //get the time and age of the customer
    int age;
    long long int time;
    float discount;
    char YN;
    float discount_cost;
    float ticket_cost;

    //enter age

    printf ("\n\nPlease enter your age >> ");
    scanf ("%d", &age);
    printf ("\n\nYour age >> %d.\n\n", age);

    //enter time

    CLOCK_:

    printf ("Enter the time in 24 hour format >> ");
    scanf ("%llu", &time);
    if (time <= CLOCK && time > 0)
	{
		time % CLOCK;
		printf ("\n\nTime is >> %llu", time);
	}
	else if (time < 0)
	{
		printf ("\nPlease enter a positive value for time.");
		goto CLOCK_;
	}
    printf ("\n\nThe time is %llu.\n", time);

    //check if a discount applies or not to adults

    if ((age >= ADULT) && (time >= TIMELIMIT))
	{
        DISC:

        printf ("\nEnter the adult discount >> ");
        scanf ("%f", &discount);
        if (discount < 0)
		{
			printf ("\nPlease enter a positive discount value.\n");
			goto DISC;
		}
		discount_cost = ADULTREG * (1 - discount * PERCENT);
        printf("\n\nThe applied discount is >> $%.2f percent after discounts.\n", discount_cost);

		MATINEE1:

        printf ("\n\nInclude matinee? ");
		scanf (" %c", &YN);
		switch (YN)
		{
			case 'Y':
			case 'y':
			{
				ticket_cost = discount_cost + ADULTMAT;
				printf ("Total adult ticket cost >> $%.2f.\n\n", ticket_cost);
			}
			case 'N':
			case 'n':
			{
				ticket_cost = discount_cost;
				printf ("Total adult ticket cost >> $%.2f.\n\n", ticket_cost);
			}
			default:
			{
				exit (0);
			}
		}
	}

	//if the person is less than 14 years of age

	else if ((age < ADULT) && (time < TIMELIMIT))
	{
        ticket_cost = CHILDREG;

        MATINEE2:

        printf ("\nInclude matinee? ");
        scanf (" %c", &YN);
        switch (YN)
        {
			case 'Y':
			case 'y':
			{
				ticket_cost = CHILDREG + CHILDMAT;
				printf ("The children ticket cost is >> $%.2f.\n\n", ticket_cost);
			}
			case 'N':
			case 'n':
			{
				ticket_cost = CHILDREG;
				printf ("The children ticket cost is >> $%.2f.\n\n", ticket_cost);
			}
			default:
			{
				exit (0);
			}
        }
	}
	return (0);
}

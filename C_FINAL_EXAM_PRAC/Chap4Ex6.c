//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//MACROS

#define SC 0.15
#define CHECK 1000.00
#define SAVINGS 1500.00

int main (int argc, char * argv [ ])
{
    //define variables here

    double check_account, savings_account;
    int cheque_books;
    double service_fee;

    //get user input

    printf ("\n\nEnter $ in checking account >> ");
    scanf ("%lf", &check_account);

    printf ("\n\nEnter $ in savings account >> ");
    scanf ("%lf", &savings_account);

    printf ("\n\nChecking Acct\tSavings Acct\n");
    printf ("$%.2lf\t$%.2lf\n", check_account, savings_account);

    //find out how many checks are ordered

    CH_BKS:

    printf ("\nHow many cheque books do you need? ");
    scanf ("%d", &cheque_books);
    if (cheque_books < 0)
	{
		printf ("\n\nInvalid number of cheque books. Please enter a positive value.");
		goto CH_BKS;
	}

    //check if checking account is less than $1000 and if savings account is less than $1500

    if ((check_account >= CHECK) && (savings_account >= SAVINGS))
	{
        printf ("\nThere is no service charge for cheque books on your account.\n\n");
	}

	//if a service fee applies

	else if ((check_account < CHECK) || (savings_account < SAVINGS))
	{
		service_fee = cheque_books * SC;
		printf ("\nThe service fee $%.2lf.\n\n", service_fee);
	}

	return (0);
}

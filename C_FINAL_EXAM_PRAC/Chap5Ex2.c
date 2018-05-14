/************************************************************************
XINYU HADRIAN HU
PROGRAM TO CALCULATE HOW MANY SECONDS IT TAKES TO GET TO N ATOMS
28/04/2018
************************************************************************/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define DIV 2

int time (long long int a);

int main (int argc, char * argv)
{

	long long int atoms;
	long long int secs;
	int counter;

	//get user input

	printf ("\nHow many atoms are there? ");
	scanf ("%d", &atoms);

	printf ("\nThere are %d atoms.\n", atoms);

    //calculate how many seconds it takes to get to this many atoms

	counter = time (atoms);

	return (0);
}

int time (long long int a)
{
    long long int counter = 0;
    long long int seconds;
    long long int temp;
    //temporary storage for a (atoms) for later reference call
    temp = a;
    while (a /= DIV != 0)
	{
		a /= DIV;
		if (a == 0)
		{
			break;
		}
		++counter;
	}
	seconds = counter;

	printf ("\nIt takes %llu seconds to get to %d atoms.\n\n", seconds, temp);

	return (seconds);
}

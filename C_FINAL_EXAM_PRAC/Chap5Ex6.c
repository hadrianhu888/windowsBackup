/****************************************************************************************

XINYU HADRIAN HU
C PROGRAM TO VALIDATE USER INPUT
BETWEEN NUMBERS 1 AND 100

****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 100

int main (int argc, char * argv [ ])
{
    int i;
	double input;

    do
	{
        INPUT:

        printf ("\nEnter your input value >> ");
        scanf ("%lf", &input);
        if (input < MIN || input > MAX)
		{
			goto INPUT;
		}
        printf ("\nValue >> %.3lf\n\n", input);

	} while (input >= MIN && input <= MAX);

	return (0);

}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define SIGN -1.0

int main (int argc, char * argv [ ])
{
    double num;
    double abs_num;

    printf ("\n\nEnter the number >> ");
    scanf ("%lf", &num);
    printf ("\nYou entered >> %lf", num);

    if (num < 0)
	{
		abs_num = SIGN * num;
	}
	else
	{
		abs_num = num;
	}

	printf ("\n\nThe absolute value is >> %lf\n\n", abs_num);

	return (0);
}

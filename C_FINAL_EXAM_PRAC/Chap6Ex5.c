#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159
#define TRUE 1
#define FALSE 0

void returnVal (double n1, double n2)
{
	double min, max;

	if (n1 < 0 && n2 < 0)
	{
		if (n1 < n2)
		{
			min = n1;
		}
		else if (n2 < n1)
		{
			min = n2;
		}
		printf ("\nMin = %.3lf\n\n", min);
	}
	else if (n1 > 0 && n2 > 0)
	{
		if (n1 > n2)
		{
			max = n1;
		}
		else if (n2 > n1)
		{
			max = n2;
		}
		printf ("\nMax = %.3lf\n\n", max);
	}
	else if ((n1 > 0 && n2 < 0) || (n2 > 0 && n1 < 0))
	{
		printf ("\nValue = 0\n\n");
	}
}

int main (int argc, char * argv [ ])
{

	double n1, n2;
    printf ("\nEnter the first number: ");
    scanf ("%lf", &n1);
	printf ("\nEnter the second number: ");
    scanf ("%lf", &n2);

    printf ("\nFirst >> %.3lf\tSecond >> %.3lf\n\n", n1, n2);

    returnVal (n1, n2);

	return (0);
}

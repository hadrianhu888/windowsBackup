#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printVals (long long int n1, long long int n2)
{

	long long int i = 0;
	if (n1 <= n2)
	{
		printf ("%llu.\t%llu\n", n2 - n1 + 1, n1);
		n1++;
		printVals (n1, n2);
	}

	printf ("\n\n");
}

void swap (long long int * x, long long int * y)
{
	long long int temp;

	temp = * x;
	* x = * y;
	* y = temp;
}

int main (int argc, char * argv [ ])

{

    long long int n1, n2;

    printf ("\nEnter the first number >> ");
    scanf ("%llu", &n1);

    printf ("\nEnter the second number >> ");
    scanf ("%llu", &n2);

	if (n2 < n1)
	{
		swap (n1, n2);
	}
	printf ("\nPrinted Values >> \n\n");
    printVals (n1, n2);

	return (0);
}

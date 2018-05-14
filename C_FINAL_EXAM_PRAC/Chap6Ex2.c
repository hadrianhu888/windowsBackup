#include <math.h>
#include <stdio.h>
#include<stdlib.h>

#define PI 3.14159

long long int power (long long int n1, long long int n2)
{
    long long int result;
    int i;

    if (n2 == 0)
	{
		result = 1;
	}
    else if (n2 == 1)
	{
		result = n1;
	}
	else if (n2 > 1)
	{
		result = n1 * power (n1, n2 - 1);
	}

	printf ("\nPower of %llu and %llu >> %llu\n\n", n1, n2, result);

	return (result);
}

int main (int argc, char * argv [ ])

{
	long long int powResult, n1, n2;

    printf ("\n\nEnter n1 and n2 values >> ");
    scanf ("%llu%llu", &n1, &n2);

    powResult = power (n1, n2);

	return (0);
}

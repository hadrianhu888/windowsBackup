#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

long long int n1 = 1;
long long int n2 = 1000;

void display1 (void)
{
	//go from n1 to n2 without using loops only recursion

	if (n1 <= n2)
	{
		printf ("%llu\n", n1);
		n1++;
		display2 ();
	}
	else
	{
		return;
	}
}

void display2 (void)
{
	if (n1 <= n2)
	{
		printf ("%llu\n", n1);
		n1++;
		display1 ();
	}
	else
	{
		return;
	}
}

int main (int argc, char * argv [ ])
{

	display1 ( );
	return (0);
}

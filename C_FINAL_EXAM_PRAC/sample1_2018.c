#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * argv [ ])
{
	int age, senior;
	do
	{
		printf ("\nEnter age >> ");
		scanf ("%d", &age);
		if (age < 0)
		{
			printf ("\nAge must be a positive value.\n");
		}
		senior = (age >= 65);
		if (! senior)
			printf ("You do not qualify for the seniors discount \n");
		else
			printf ("You qualify for the seniors discount");

		if (age > 130)
		{
			printf ("\nThe program will now exit.\n");
			exit (0);
		}

	} while (age > 0 && age < 130);

	return (0);
}

#include <stdio.h>

int main (int argc, char * argv [ ])
{
    float a = 10.5;

    printf ("===FIRST CONDITION\n");
    if (sizeof (a) == sizeof (10.5))
	{
		printf ("Matched!\n\n");
	}
	else
	{
		printf ("Not matched!\n\n");
	}

	printf ("===SECOND CONDITION\n");
    if (sizeof (a) == sizeof (10.5f))
	{
		printf ("Matched!\n\n");
	}
	else
	{
		printf ("Not matched!\n\n");
	}

	printf ("===THIRD CONDITION\n");
    if (sizeof ( (double) a) == sizeof ( (double) 10.5))
	{
		printf ("Matched!\n\n");
	}
	else
	{
		printf ("Not matched!\n\n");
	}

	printf ("===FOURTH CONDITION\n");
    if (a == 10.5f))
	{
		printf ("Matched!\n\n");
	}
	else
	{
		printf ("Not matched!\n\n");
	}
	printf ("\n\n");
	return (0);
}

//error during compiling

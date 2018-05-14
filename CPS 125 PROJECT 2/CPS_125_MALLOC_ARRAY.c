#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main (int argc, char * argv [ ])
{
    double **** p;

    int i, j, k, m;
	int l, w, h, t;

	printf ("\nEnter the length of your array >> ");
	scanf ("%d", &l);
	printf ("\nEnter the width of your array >> ");
	scanf ("%d", &w);
	printf ("\nEnter the height of your array >> ");
	scanf ("%d", &h);
	printf ("\nEnter the time-domain of your array >> ");
	scanf ("%d", &t);

	printf ("\nLength >>\t%d\nWidth >>\t%d\nDepth >>\t%d\nTime >>\t\t%d\n", l, w, h, t);

	printf ("\n\n");

    p = (int ****) malloc (l * sizeof (int ****));
    if (p == NULL)
	{
		printf ("\nNot enough memory!\n");
		exit (0);
	}
	for (i = 0; i < l; ++i)
	{
		p [i] = (int ***) malloc (w * sizeof (int ***));
		if (p [i] == NULL)
		{
			printf ("\nNot enough memory!\n");
			exit (0);
		}
	}
	for (i = 0; i < l; ++i)
	{
		for (j = 0; j < w; ++j)
		{
			p [i] [j] = (int **) malloc (h * sizeof (int **));
			if (p [i] [j] == NULL)
			{
				printf ("\nNot enough memory!\n");
				exit (0);
			}
 		}
	}
	for (i = 0; i < l; ++i)
	{
		for (j = 0; j < w; ++j)
		{
			for (k = 0; k < h; ++k)
			{
				p [i] [j] [k] = (int *) malloc (t * sizeof (int *));
				if (p [i] [j] [k] == NULL)
				{
					printf ("\nNot enough memory!\n");
					exit (0);
				}
			}
		}
	}
    for (i = 0; i < l; ++i)
	{
		for (j = 0; j < w; ++j)
		{
			for (k = 0; k < h; ++k)
			{
				for (m = 0; m < t; ++m)
				{
					printf ("Enter p [%d] [%d] [%d] [%d] >> ", (i + 1), (j + 1), (k + 1), (m + 1));
					scanf ("%lf", &p [i][j][k][m]);
					printf ("p [%d] [%d] [%d] [%d] >> %8.3lf\n", (i + 1), (j + 1), (k + 1), (m + 1), p [i] [j] [k] [m]);
				}
			}
		}
	}
	printf ("\n\n4D Array Result >> \n\n");

	for (i = 0; i < l; ++i)
	{
		for (j = 0; j < w; ++j)
		{
			for (k = 0; k < h; ++k)
			{
				for (m = 0; m < t; ++m)
				{
					printf("%.3lf\t", p [i][j][k][m]);
				}
				printf ("\n");
			}
			printf ("\n");
		}
		printf ("\n");
	}
	printf ("\n");

    for (i = 0; i < l; ++i)
	{
		for (j = 0; j < w; ++j)
		{
			for (k = 0; k < h; ++k)
			{
				for (m = 0; m < t; ++m)
				{
					free (p [i] [j] [k]);
				}
				free (p [i] [j]);
			}
			free (p [i]);
		}
		free (p);
	}
	return (0);
}

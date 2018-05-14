#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define STRING_MAX 30

int code [MAX];
char descr [MAX][STRING_MAX];
double price [MAX];

double scanner (char descr [MAX][STRING_MAX], double price [MAX], int scancode, int * location);


int main (int argc, char * argv)

{

    double scan;
    int * position;
    int scan_code;
    int i, j, k;
    char descr [MAX][STRING_MAX];
    double price [MAX];

    printf ("\nEnter the bar code >> ");
    scanf ("%d", &scan_code);

    //call the function here

    scan = scanner (descr, price, scan_code, &position);

	return (0);
}

double scanner (char descr [MAX][STRING_MAX], double price [MAX], int scancode, int * location)
{
	double scan;
	int * position;
	int scan_code;
	int i, j, k;

    for (i = 0; i < MAX; ++i)
	{
		if (scancode == code [i])
		{
            printf ("\nThis is a product bar code.\n\n");
            j = i;
            k = i;
            descr [j][STRING_MAX] = descr [i][STRING_MAX];
            * position = i + 1;
            price[k] = price [i];

            printf ("\nDescription >> %s\nPrice = $%.2lf\nPosition >> %d.\n\n", descr, price, * position);
		}
		else
		{
			printf ("\nThis is not a valid bar code.\n\n");
			exit (1);
		}
	}
}

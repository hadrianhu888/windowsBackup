#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159
#define TRUE 1
#define FALSE 0

double zVal (double x, double y)
{
	double z;

	z = (sqrt(sqrt((pow (x, 2)/ pow (y, 2) + 3 * x + 5 / (pow (y, 2)) - 2))))/ (x - 1);

	printf ("\nz = %.3lf\n\n", z);

	return (z);
}

int main ( int argc, char * argv [ ] )
{

	double x, y, z;

	printf ("\nEnter values for x and y >> ");
	scanf ("%lf%lf", &x, &y);
	printf ("\nx = %.3lf\ty = %.3lf\n\n", x, y);

	z = zVal (x, y);

	return (0);
}

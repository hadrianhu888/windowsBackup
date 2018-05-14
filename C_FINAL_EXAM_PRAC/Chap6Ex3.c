#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159
#define CIRCLE 180
#define DEG_RAD PI / CIRCLE

double areaSector (int radius, double theta)
{
    double area;
    area  = pow (radius, 2) * (theta * DEG_RAD) / 2;

    if (area > 100)
	{
		area = (int) area;
	}

    printf ("Area of the Sector>> %.3lf\n\n", area);
	return (area);
}

int main (int argc, char * argv [])
{

	double area, theta;
	int radius;

    printf ("\nEnter radius >> ");
    scanf ("%d", &radius);

    printf ("\nEnter theta >> ");
    scanf ("%lf", &theta);

    printf ("\nRadius >> %d\tTheta in Radians >> %.3lf\n\n", radius, theta * DEG_RAD);

	area = areaSector (radius, theta);

	return (0);
}

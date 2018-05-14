#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

double quadratic (double a, double b, double c, double * result2)

{
	double q1, q2;

	double det = pow (b, 2) - (4 * a * c);

	if (det < 0)
	{
		q1 = - (b + sqrt (abs (det)) / (2 * a));
		q2 = - (b - sqrt (abs (det)) / (2 * a));
		* result2 = q2;
		printf ("\nResult 1 >> %.3lf - %.3lfi\tResult 2 >> %.3lf + %.3lfi\n\n",
				- b / (2 * a),
				- abs (det) / (2 * a),
				- b / (2 * a),
				abs (det) / (2 * a));
	}
	else if (det == 0)
	{
		q1 =  - b / (2 * a);
		q2 = q1;

		* result2 = q2;

		printf ("\nResult 1 >> %.3lf\tResult 2 >> %.3lf\n\n", q1, &result2);

	}
	else if (det > 0)
	{
		q1 = - b + det / (2 * a);
		q2 = - b - det / (2 * a);

		* result2 = q2;

		printf ("\nResult 1 >> %.3lf\tResult 2 >> %.3lf\n\n", q1, &result2);

	}

    return (q1);
}

int main ( int argc, char * argv [ ] )

{
	double a, b, c, r1, r2;

	printf ("\nEnter a, b and c >> ");
	scanf ("%lf%lf%lf", &a, &b, &c);

	printf ("\na = %.3lf\tb = %.3lf\tc = %.3lf\n\n", a, b, c);

	r1 = quadratic (a, b, c, &r2);

	return (0);
}

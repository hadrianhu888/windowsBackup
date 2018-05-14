	#include <stdio.h>
	int
	main (int argc, char *argv[])
	{
	   int number, square;
	   double sroot;
	   FILE *out;
	   out = fopen ("q1.txt", "w");
	   number = 20;
	   sroot = sqrt (number);
	   square = number * number;
	   printf ("%5d %5.1lf\n", square, sroot);
	   fprintf (out, "%5d %5.1lf\n", square, sroot);
	   fclose (out);
	   return (0);
	}


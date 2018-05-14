//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//MACRROS

#define MIN_PRESS 25.00
#define MAX_PRESS 40.00

int main (int argc, char * argv [ ])
{
    //variables declared here

    double ptirefR, ptirefL, ptirerR, ptirerL;
    double ftireP, rtireP;
    char next_vehicle;

    do
	{
		//get user input

		FRONT_TIRE_P:

		printf ("\n\nEnter front right tire pressure >> ");
		scanf ("%lf", &ptirefR);

		printf ("\n\nEnter front left tire pressure >> ");
		scanf ("%lf", &ptirefL);

		//check if front two tires are within range and are same pressure

		if (ptirefR != ptirefL)
		{
			printf ("\n\nFront right and front left tire pressures must be the same.\n\n");
			goto FRONT_TIRE_P;
		}
		else if (ptirefR == ptirefL)
		{
			ftireP = ptirefR;
			goto REAR_TIRE_P;
		}

		//check rear tire pressure to see if they are the same pressure

		REAR_TIRE_P:

		printf ("\n\nEnter rear right tire pressure >> ");
		scanf ("%lf", &ptirerR);

		printf ("\n\nEnter rear left tire pressure >> ");

		//check for rear left and rear right tire pressure

		scanf ("%lf", &ptirerL);

		if (ptirerR != ptirerL)
		{
			printf ("\n\nRear right and rear left tire pressures must be the same.\n\n");
			goto REAR_TIRE_P;
		}
		else if (ptirerR == ptirerL)
		{
			rtireP = ptirerR;
		}

		//check if the pressure is within range of the acceptable psi and print out the results

		if ((ftireP >= MIN_PRESS && ftireP <= MAX_PRESS) && (rtireP >= MIN_PRESS && rtireP <= MAX_PRESS))
		{
			printf ("\n\nYour tire pressures satisfy the requirements of a road-worthy vehicle.\n");
			printf ("\nF.R.Tire\tF.L.Tire\tLR.R.Tire\tR.L.Tire\n\n");
			printf ("%.3lf psi\t%.3lf psi\t%.3lf psi\t%.3lf psi\n\n", ptirefR, ptirefL, ptirerR, ptirerL);
		}

		else if ((ftireP < MIN_PRESS && ftireP > MAX_PRESS) || (rtireP < MIN_PRESS && rtireP > MAX_PRESS))
		{
			printf ("\n\nYour tire pressures do not satisfy the requirements for a road-worthy vehicle.\n");
			printf ("\nF.R.Tire\tF.L.Tire\tLR.R.Tire\tR.L.Tire\n\n");
			printf ("%.3lf psi\t%.3lf psi\t%.3lf psi\t%.3lf psi\n\n", ptirefR, ptirefL, ptirerR, ptirerL);
			printf ("Tire pressures must be between 25.00 psi and 40.00 psi.\n\n");
		}

		//check if the user wants to input another vehicle

		printf ("\nDo you want to check another vehicle? ");
		scanf (" %c", &next_vehicle);
		if (next_vehicle != 'Y' || next_vehicle != 'y')
		{
			printf ("\nThe program will now exit.\n\n");
			exit (0);
		}

	} while (next_vehicle == 'y' || next_vehicle == 'Y');

	return (0);
}

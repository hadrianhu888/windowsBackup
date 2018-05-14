#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SNOWPLOW 0.60

int main ( int argc, char * argv [ ] )
{
    double drive_length, drive_width;
    double walking;

    //get user input

	LENGTH:

    printf ("\nEnter the length of the drive way >> ");
    scanf ("%lf", &drive_length);
    if (drive_length <= 0)
	{
		goto LENGTH;
	}
	else
	{
		goto WIDTH;
	}
	WIDTH:
    printf ("\nEnter the width of the drive way >> ");
    scanf ("%lf", &drive_width);
    if (drive_width <= 0)
	{
		goto WIDTH;
	}
	else
	{
		goto RESULTS;
	}
    RESULTS:

    //print out the length and width for user verification

    printf ("Driveway Length >> %.3lf meters\nDriveway Width >> %.3lf meters\n", drive_length, drive_width);

    //calculate total length to walk to clear away all of the snow

	walking = (drive_width / SNOWPLOW) * drive_length;

    printf ("\n\nTotal Walking Distance to Clear all of the Snow in the Given Driveway of %.3lf m X %.3lf m >> %.3lf m.\n", drive_width,
			drive_length, walking);
    printf ("\nTherefore, the you must walk %.3lf meters to clear all of the snow.", walking);

	return (0);
}

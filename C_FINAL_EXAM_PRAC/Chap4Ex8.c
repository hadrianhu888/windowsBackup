//PREPROCESSORS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//MACROS

#define TWO_ITEMS 1.5
#define THREE_ITEMS 2.0
#define SEC_MIN 60

#define MAX 3
#define MED 2
#define MIN 1

//DEFINE STRUCT

typedef struct cookTime
{
	int min;
	int sec;

} CTimer;

int main (int argc, char * argv [ ])
{
    //variables

    int items;
	CTimer heat_time;
	CTimer total_heat_time;
	char choice;

	//user input

	ITEMS_HEAT:

    printf ("\n\nEnter the number of items to heat >> ");
    scanf ("%d", &items);
    if (items > MAX)
	{
        printf ("\n\nHeating more than 3 items at once is not recommended.\n");
        goto ITEMS_HEAT;
	}
    else if (items == MAX)
	{
        printf ("\nEnter the cook time for the item requiring the \n\nlongest time to microwave separating the minute and second with a space>> ");
        scanf ("%d%d", &heat_time.min, &heat_time.sec);

        //check that if there is any extra seconds, they are added to the minutes

        if (heat_time.sec > SEC_MIN)
		{
            heat_time.min = heat_time.sec / SEC_MIN;
            heat_time.sec = heat_time.sec % SEC_MIN;
		}
        printf ("\n\nThe item requiring the longest heating time is >> %d:%d.\n\n", heat_time.min, heat_time.sec);
        total_heat_time.sec = THREE_ITEMS * (heat_time.min * SEC_MIN + heat_time.sec);
        total_heat_time.min = total_heat_time.sec / SEC_MIN;
        total_heat_time.sec = total_heat_time.sec % SEC_MIN;
        printf ("\n\nTotal heating time for three(3) items >> %d:%d\n\n", total_heat_time.min, total_heat_time.sec);
	}
	else if (items == MED)
	{
		printf ("\nEnter the cook time for the item requiring the \n\nlongest time to microwave separating the minute and second with a space>> ");
        scanf ("%d%d", &heat_time.min, &heat_time.sec);

        //check that if there is any extra seconds, they are added to the minutes

        if (heat_time.sec > SEC_MIN)
		{
            heat_time.min = heat_time.sec / SEC_MIN;
            heat_time.sec = heat_time.sec % SEC_MIN;
		}
        printf ("\n\nThe item requiring the longest heating time is >> %d:%d.\n\n", heat_time.min, heat_time.sec);
        total_heat_time.sec = TWO_ITEMS * (heat_time.min * SEC_MIN + heat_time.sec);
        total_heat_time.min = total_heat_time.sec / SEC_MIN;
        total_heat_time.sec = total_heat_time.sec % SEC_MIN;
        printf ("\n\nTotal heating time for two(2) items >> %d:%d\n\n", total_heat_time.min, total_heat_time.sec);
	}

	else if (items == MIN)
	{
		printf ("\nEnter the cook time for the item requiring the \n\nlongest time to microwave separating the minute and second with a space>> ");
        scanf ("%d%d", &heat_time.min, &heat_time.sec);

        //check that if there is any extra seconds, they are added to the minutes

        if (heat_time.sec > SEC_MIN)
		{
            heat_time.min = heat_time.sec / SEC_MIN;
            heat_time.sec = heat_time.sec % SEC_MIN;
		}
        printf ("\n\nThe item requiring the longest heating time is >> %d:%d.\n\n", heat_time.min, heat_time.sec);
        total_heat_time.sec = heat_time.min * SEC_MIN + heat_time.sec;
        total_heat_time.min = total_heat_time.sec / SEC_MIN;
        total_heat_time.sec = total_heat_time.sec % SEC_MIN;
        printf ("\n\nTotal heating time for one(1) items >> %d:%d\n\n", total_heat_time.min, total_heat_time.sec);
	}
	else
	{
		printf ("\n\nNo item to heat.\n");
        printf ("\nExit now? ");
        scanf (" %c", &choice);

	}

	return (0);
}

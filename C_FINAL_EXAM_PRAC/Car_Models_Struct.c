//preprocessors

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

//macros

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define STRING_LENGTH 20
#define END "END"

typedef struct vehicles
{
    char model [STRING_LENGTH];
    char manufacturer [STRING_LENGTH];
    char color [STRING_LENGTH];
    long long int year;

    struct vehicle * next;

} veh;

int main (int argc, char * argv [ ])
{
	char colors [STRING_LENGTH];
	char model [STRING_LENGTH];
	char manuf [STRING_LENGTH];
	char year_man [5];
	long long int yr;

	veh * p, * start;

    start = NULL;

    //enter the first tree

    printf ("Enter car model, manufacturer\ncolor and year of production (END to finish) >> ");
    printf ("\nEnter Model >>");
    //scanf ("%s", model);
	fgets (model, sizeof (model), stdin);
	model [ strlen(model) - 1 ] = '\0';
	printf ("\nEnter Manufacturer >>");
	//scanf ("%s", manuf);
	fgets (manuf, sizeof (manuf), stdin);
	manuf [strlen (manuf) - 1 ] = '\0';
    printf ("\nEnter Colour >>");
    fgets (colors, sizeof (colors), stdin);
    colors [strlen (colors) - 1 ] = '\0';
    printf ("\nEnter Year >>");
    scanf ("%llu", &yr);

    while (strcmp (model, "END") != 0 || strcmp (manuf, "END") != 0 || strcmp (colors, "END") != 0 || strcmp ((char) yr, "END") != 0)
	{
        p = (veh *) calloc (1, sizeof (veh));

        strcpy (p -> model, model);
        strcpy (p -> manufacturer, manuf);
        strcpy (p -> color, colors);
        p -> year, yr;

        p -> next = start;

        start = p;

        printf ("Enter first car model, manufacturer\ncolor and year of production (END to finish) >> ");
		printf ("\nEnter Model >>");
		//scanf ("%s", model);
		fgets (model, sizeof (model), stdin);
		model [ strlen(model) - 1 ] = '\0';
		printf ("\nEnter Manufacturer >>");
		//scanf ("%s", manuf);
		fgets (manuf, sizeof (manuf), stdin);
		manuf [strlen (manuf) - 1 ] = '\0';
		printf ("\nEnter Colour >>");
		fgets (colors, sizeof (colors), stdin);
		colors [strlen (colors) - 1 ] = '\0';
		printf ("\nEnter Year >>");
		scanf ("%llu", &yr);

	}

	p = start;

	printf ("\n\nModel\tManuf\tColor\tYear\n\n");

    while (p != NULL)
	{
        printf ("%s\t%s\t%s\t%llu\n", p->model, p->manufacturer, p->color, p->year);
        p = p -> next;
	}

	return (0);
}






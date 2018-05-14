#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PI 3.14159
#define STR_MAX 50

int main (int argc, char * argv [ ])
{

	char userString [STR_MAX];
	char newString [STR_MAX];
	char * subString;
	char * xString;
	char userChar;
	int i, j, k;
	char * tempA;
	char * tempB;
	char * finalString;

	//user input

    printf ("\nEnter a string >> ");
    fgets (userString, STR_MAX, stdin);

	subString = strstr (userString, "th");
	strncpy (subString, "%%", STR_MAX);
	* tempA = puts (userString);


    xString = strstr (userString, "x");
    strncpy (xString, "?", STR_MAX);
	* tempB = puts (userString);

	* finalString = strcat (&tempA, &tempB);

	//printf ("\n%s", &finalString);
	return (0);
}

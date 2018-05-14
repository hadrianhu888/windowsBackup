
/**********************************************************************

						XINYU HADRIAN HU
							02/05/2018

		C PROGRAM TO SUBSTITUTE A CHARACTER WITH ANOTHER
		 C PROGRAM TO SUBSTITUTE A STRING WITH ANOTHER

**********************************************************************/

//preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//string maximum length value

#define MAX 50

//function prototypes

void replaceAll (char * str, char oldC, char newC);
void replaceSubString (char * str, char * sub, char * rep);

//start of the program

int main (int argc, char * argv [ ])
{
	//declaring variables

	char userString [MAX];
	char oldChar, newChar;

	//for strings and sub-strings

	char oldString [MAX];
    char subString [MAX];
    char newString [MAX];

    //user input

	printf ("\nEnter a string >> ");
	fgets (userString, MAX, stdin);

	printf ("\nPrint character to replace >> ");
	oldChar = getchar ();
	getchar();

	printf ("\nPrint new character >> ");
	newChar = getchar();
	getchar ();

	//before replacement

	printf ("\nString before Replacement >> %s\n\n", userString);

	printf ("\nReplacing %c with %c in string %s >> \n\n", oldChar, newChar, userString);

	replaceAll (userString, oldChar, newChar);

	//string replacement

	printf ("\nNew string after replacing %c with %c >> %s\n\n", oldChar, newChar, userString);

	printf ("\nThe original string is after changing %c to %c >> %s", oldChar, newChar, userString);

	printf ("\nEnter the sub-string >> ");
	fgets (subString, MAX, stdin);

    printf ("\nEnter a new substitute sub-string >> ");
    fgets (newString, MAX, stdin);

    printf ("\nReplacing %s with %s in the string %s >> \n\n", subString, newString, userString);

    replaceSubString (userString, subString, newString);

    //after replacing one string with another

    printf ("\nAfter replacing %s with %s >> %s.\n\n", subString, newString, userString);

	return (0);
}

//replace character function

void replaceAll (char * str, char oldC, char newC)
{
	int i;
	while (str [i] != '\0')
	{
		if (str [i] == oldC)
		{
			str[i] = newC;
		}
		++i;
	}
}

//replace sub-string function

void replaceSubString (char * str, char * sub, char * rep)
{
	int strLen, subLen, newLen;
    int i = 0, j, k;
    int flag = 0;
    int start, end;
    strLen = strlen (str);
    subLen = strlen (sub);
    newLen = strlen (rep);

    for (i = 0; i < strLen; ++i)
	{
        flag = 0;
        start = i;
        for (j = 0; str[i] == sub [j]; j++, i++)
		{
			if (j == subLen - 1)
			{
                flag = 1;
                end = i;
			}
			if (flag == 0)
			{
				i -= j;
			}
			else
			{
				for (j = start; j < end; j++)
				{
					for (k = start; k < strLen; k++)
					{
						str [k] = str [k + 1];
						strLen--;
						i--;
					}
				}
			}
		}
	}
	for (j = start; j < start + newLen; j++)
	{
		for (k = strLen; k >= j; k--)
		{
			str [k + 1] = str [k];
			str [j] = rep [j - start];
			strLen++;
			i++;
		}
	}
}

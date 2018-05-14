/**
Program to enter bank account information into a file using linked lists
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <assert.h>

//what the structure looks like:

struct account
{
	int number;
	char lastname [15];
	char firstname [15];
	float balance;
	struct account * next;
};

typedef struct account * firsta, * currenta, * newa, * previousa;

/**Function prototypes**/

void accountInput (struct account * p, int size);
void accountOutput (struct account * p, int size);

//start of main program here

int main (int argc, char * argv [ ])
{
    FILE * datafile;
    char * filename = "bank.dat";
    datafile = fopen (filename, "w");

    struct account * p;
    int size;
    int choice = 1;
    firsta = 0;
    currenta = firsta;

    printf ("Enter how many accounts you like to enter >> ");
    scanf ("%d", &size);

    printf ("Number of account to input >> %d\n", size);

    p = (struct account *) malloc (size * sizeof (struct account));

    if (p == NULL)
	{
		puts ("Not enough memory!\n");
		exit(0);
	}

    /** get the user to input data **/

    accountInput (p, size);

    /**output on screen before while writing to file **/

    accountOutput (p, size);

    free(p);

    fclose (datafile);

	return (0);
}


void accountInput (struct account * p, int size)
{

}
void accountOutput (struct account * p, int size)
{

}

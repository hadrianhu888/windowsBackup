#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <windows.h>

void clearInput (void);
void addNewAccount (void);
void listAll (void);
void deleteAccount (void);
void modifyAccount (void);
int prompt (void);

struct account
{
	int number;
	char lastname [15];
	char firstname [15];
	float balance;
	struct account * next;
};

struct account * firsta, * currenta, * newa;

int anum = 0;

int main (int argc, char * argv [ ])
{
    FILE * datafile;
    char * filename = "bank.dat";
    char ch;
    firsta = NULL;

    datafile = fopen (filename, "r");
    if (datafile == NULL)
	{
		printf ("The file does not exist. The program will now exit.\n\n");
		exit (0);
	}
    firsta = (struct account *) malloc (sizeof (struct account));
    currenta = firsta;
    while (1)
	{
        newa = (struct account *) malloc (sizeof (struct account));
        fread (currenta, sizeof (struct account), 1, datafile);
        {
        	break;

        }
		currenta -> next = newa;
        currenta = newa;
	}
    do
	{
        clearInput ();
        puts ("\nA - Add a new account");
        puts ("\nD - Delete account");
        puts ("\nL - List all accounts");
        puts ("\nM - Modify account");
        puts ("\nQ - Quit this program\n");
        printf ("\nYour choice : ");
        ch = getchar ();
        ch = toupper (ch);
        switch (ch)
        {
		case 'A':
			{
                puts ("Add new account\n");
                clearInput();
                addNewAccount();
                break;
			}
		case 'D':
			{
                puts ("Delete account\n");
                clearInput ();
                deleteAccount ();
                break;
			}
		case 'L':
			{
                puts ("List all accounts\n");
                clearInput();
                listAll ();
                break;
			}
		case 'M':
			{
				puts ("M - Modify account\n");
				modifyAccount ();
				break;
			}
		case 'Q':
			{
				puts ("Q - Quit the program\n");
			}
		default:
			{
				break;
			}
        }
	} while (ch != 'Q');

    /**Save the records to disk**/

    currenta = firsta;
    if (currenta == NULL)
	{
        return (0);
	}
	datafile = fopen (filename, "w");
    if (datafile == NULL)
	{
        printf ("\nError writing to %s.\n", filename);
        return (1);
	}
	while (currenta != NULL)
	{
        fwrite (currenta, sizeof (struct account), 1, datafile);
        currenta = currenta -> next;
	}
	fclose (datafile);
	return (0);
}

/** This function clears away any text from the input stream**/

void clearInput (void)
{
	fflush (stdin);
}
/** Creates a new account **/

void addNewAccount (void)
{
    newa = (struct account *) malloc (sizeof (struct account));

    /** Check if this is the first record. If so, then initialize all the pointers to this first structure in the database**/

    if (firsta == NULL)
	{
		firsta = currenta = newa;
	}

	/** Otherwise you must find the end of the structure list (easily spotted by the NULL pointer) and add on the new structure you just allocated memory for
**/

    else
	{
        currenta = firsta;

        while (currenta -> next != NULL)
		{
            currenta = currenta -> next;
		}
		currenta -> next = newa;
		currenta = newa;
	}

	/** Now just fill in the new structure **/

    anum ++;
    printf ("%27s: %5i\n", "Account Number", anum);
    currenta -> number = anum;

    printf ("%27s: ", "Enter customer's last name");
    gets (currenta -> lastname);

    printf ("%27s: ", "Enter customer's first name");
    gets (currenta -> firstname);

    printf ("%27s: $", "Enter customer account balance");
    scanf ("%f", currenta -> balance);

    /** cap the last record with a NULL so you know that it is the last record in the list of records **/

    currenta -> next = NULL;
}

void listAll (void)
{
    if (firsta == NULL)
	{
		puts ("\nThere are no records to print.\n");
	}
	else
	{
		printf ("%6s %-15s %-15s %1ls\n", "Acct #", "Last", "First", "Balance");
		currenta = firsta;
		do
		{
			printf ("%5d: %-15s %-15s $%8.2f\n",
					currenta -> number,
					currenta -> lastname,
					currenta -> firstname,
					currenta -> balance);
		}
		while ((currenta = currenta -> next)!= NULL);
	}
}
void deleteAccount (void)
{
    int record;
    struct account * previousa;
    if (firsta == NULL)
	{
        puts ("There are no records to delete!\n");
        return;
	}
	listAll();
	printf ("\nEnter account number to delete: ");
	scanf ("%d", &record);

    currenta = firsta;

    while (currenta != NULL)
	{
        if (currenta -> number == record)
		{
            if (currenta == firsta)
			{
				firsta = currenta -> next;
			}
			else
			{
				previousa -> next = currenta -> next;
			}
            free (currenta);
            printf ("Account %d has been deleted!\n", record);
            return;
		}
		else
		{
            previousa = currenta;
            currenta = currenta -> next;
		}
	}
    printf ("Account %d has not been found!\n", record);
    puts ("Nothing deleted.\n");
}

/**modify account **/

void modifyAccount (void)
{
    int record;
    struct account * currenta;
    if (firsta == NULL)
	{
        puts ("There are no records to delete!\n");
        return;
	}
    listAll();
    printf ("Enter account number to modify: ");
    scanf ("%d", record);

    currenta = firsta;
    while (currenta != NULL)
	{
        if (currenta -> number == record)
		{
            printf ("Account %d: \n", currenta -> number);
            printf ("Last name: %s\n", currenta -> lastname);
            if (prompt ())
			{
				gets (currenta -> lastname);
			}
			printf ("First name: %s\n", currenta -> firstname);
			if (prompt ())
			{
				gets (currenta -> firstname);
			}
			printf ("Balance %8.2f\n", currenta -> balance);
			if (prompt ())
			{
				scanf ("%f", &currenta -> balance);
			}
			return;
		}
		else
		{
            currenta = currenta -> next;
		}
	}
	printf ("Account %d was not found!\n");
}
int prompt (void)
{
    char ch;
    clearInput ();
    printf ("Update? ");
    ch = getchar ();
    ch = toupper (ch);
    clearInput();
    if (ch == 'Y')
	{
		printf ("Enter new: ");
		return (1);
	}
	else
	{
		return (0);
	}
}

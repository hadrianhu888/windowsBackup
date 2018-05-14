/*

THIS PROGRAM PLAYS DRAW POKER
USER CAN PLAY AS OFTEN AS THEY WANT
BETTING BETWEEN 1 AND 5
PLAYESR ARE DEALT 5 CARDS AND CAN CHOOSE WHICH CARDS THEY WANT TO KEEP
THE HAND IS THEN REVIEWED AND THE PAYOUT IS UPDATED ACCORDINGLY
THE PLAYER'S BANKROLL IS UPDATED AND THEY ARE GIVEN THE OPTION TO CONTINUE

*/

//including header files and preprocessor directives

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

//defining MACROS

#define TRUE 1
#define FALSE 0

//card characteristics

#define RANK 5
#define SUITE 13
#define FACES 4

#define LINE printf("*************************************************************************\n");

//function prototyping

void printGreeting();
int getBet ();
char getSuit (int suit);
char getRank (int rank);
void getFirstHand (int cardRank [], int cardSuit []);
void getFinalHand (int cardRank [], int cardSuit [], int finalRank [], int finalSuit [], int ranksinHand [], int suitinHand []);
int analyzeHand (int ranksinHand [], int suiteinHand []);

int main (int argc, char * argv [])

{
    int bet;
    int bank = 100;
    int i;
    int cardRank [RANK]; //Will be one 13 (Ace to King)
    int cardSuit [RANK]; //Will be one of four values (Clubs, Hearts, Diamonds, Spades)

    int finalRank [RANK];
    int finalSuit [RANK];

    int ranksinHand [SUITE]; //used for evaluating the final hand
    int suitsinHand [FACES]; //used for evaluating the final hand
    int winnings;
    time_t t;
    char suit, rank, stillPlay;

    //print Greetings only once since it is outside of the main game itself

    printGreeting ();

    //run the loop until the player no longer wants to play

    do
	{
		bet = getBet ();
		srand (time(&t));
        getFirstHand (cardRank, cardSuit);
        printf ("Your five cards : \n");
        for (i = 0; i < RANK; ++i)
		{
			suit = getSuit (cardSuit [i]);
			rank = getRank (cardRank [i]);
			printf("Card #%d: %c%c\n", i + 1, rank, suit);
		}
	    //determine what is in the player's hands

		for (i = 0; i < FACES; ++i)
		{
			suitsinHand [i] = 0;
		}
		for (i = 0; i < SUITE; ++i)
		{
			ranksinHand [i] = 0;
		}

		getFinalHand (cardRank, cardSuit, finalRank, finalSuit, ranksinHand, suitsinHand);

		printf("Your five final cards : \n");
		for (i = 0; i < RANK; ++i)
		{
			suit = getSuit (finalSuit [i]);
			rank = getRank (finalRank [i]);
			printf ("Card #%d : %c%c \n", i + 1, rank, suit);
		}

		winnings = analyzeHand (ranksinHand, suitsinHand);
		printf ("You won %d\n", bet * winnings);
		bank = bank - bet + (bet * winnings);
		printf ("Your bank is now %d\n", bank);
		printf ("\nDo you want to play again? ");
		scanf ("%c", &stillPlay);

	} while (toupper (stillPlay) == 'Y');

	return (0);
}

//defining function processes

void printGreeting ()

//greeting

{
    LINE;
    printf ("Welcome to the Absolute Beginner's Casino");
    printf (" Home of Video Draw Poker!\n");
    LINE;

    //prints out the rules

    printf ("\nHere are the rules: \n");
    printf ("You start out with 100 credits, and you make a bet from 1 to 5 credits.\n");
    printf ("You are dealt 5 cards, and then you choose which cards to keep or discard.\n");
    printf ("You want to make the best possible hand.\nHere is the table for winnings (assuming a bet of credit): \n\n");
    printf ("Pair\t\t\t\t1 Credit\n");
    printf ("Two pairs\t\t\t2 Credits\n");
    printf ("Three of a kind\t\t\t3 Credits\n");
    printf ("Straight\t\t\t4 Credits\n");
    printf ("Flush\t\t\t\t5 Credits\n");
    printf ("Full House\t\t\t8 Credits\n");
    printf ("Four of a Kind\t\t\t10 Credits\n");
    printf ("Straight Flush\t\t\t20 Credits\n");
    printf ("\nHave Fun !!\n\n");
}

//function to deal first 5 cards

void getFirstHand (int cardRank [], int cardSuit [])
{
	int i, j;
	int cardDup;

    for (i = 0; i < RANK; ++i)
	{
		cardDup = 0;
		do
		{
            //card rank is one of 13 ( 2 - 10m J, Q, K, A)
            cardRank [i] = (rand() % SUITE);
            //card suit is one of four
            cardSuit [i] = (rand() % FACES);

            //loop that ensures each card is unique

            for (j = 0; j < i; ++j)
			{
				if ((cardRank[i] == cardRank [j]) && (cardSuit [i] = cardSuit [j]))
				{
                    cardDup = 1;
				}
			}
		} while (cardDup == 1);
	}
}

//function that changes the suit integer value to a character representing the suit

char getSuit (int suit)
{
	switch (suit)
	{
	case 0:
		return ('C');
		break;
	case 1:
		return ('D');
		break;
	case 2:
		return ('H');
		break;
	case 3:
		return ('S');
		break;
	}
}

//function that changes the rank integer to a character representing the rank

char getRank(int rank)
{
    switch (rank)
    {
	case 0:
		return ('A');
		break;
	case 1:
		return ('2');
		break;
	case 2:
		return ('3');
		break;
	case 3:
		return ('4');
		break;
	case 4:
		return ('5');
		break;
	case 5:
		return ('6');
		break;
	case 6:
		return ('7');
		break;
	case 7:
		return ('8');
		break;
	case 8:
		return ('9');
		break;
	case 9:
		return ('T');
		break;
	case 10:
		return ('J');
		break;
	case 11:
		return ('Q');
		break;
	case 12:
		return ('K');
		break;
    }
}

//function to get user bet from 1 to 5

int getBet()
{

	int bet;
    do
	{
        printf ("\nHow much do you want to bet ? (Enter a number between 1 to 5 or press 0 to quit the game) : ");
        scanf ("%d", &bet);
        if (bet >= 1 && bet <= 5)
		{
			return (bet);
		}
		else if (bet == 0)
		{
			exit (1);
		}
		else
		{
			printf ("\n\nPlease enter a bet from 1 to 5 or 0 to quit the game\n");
		}
	}
	while ((bet < 0) || (bet > 5));
}

//last function reviews the final hand and determines the value of the hand

int analyzeHand (int ranksinHand [], int suitsinHand [])
{
    int num_consec = 0;
    int i, rank, suit;
    int straight = FALSE;
    int flush = FALSE;
    int four = FALSE;
    int three = FALSE;
    int pairs = 0;

    for (suit = 0; suit < FACES; ++suit)
	{
		if (suitsinHand [suit] == RANK)
		{
			flush == TRUE;
		}
	}
	rank = 0;
	while (ranksinHand [rank] == 0)
	{
		rank++;
	}
	for ( ; rank < SUITE && ranksinHand [rank]; rank++)
	{
		num_consec++;
	}
	if (num_consec == RANK)
	{
		straight == TRUE;
	}
	for (rank = 0; rank < SUITE; ++rank)
	{
		if (ranksinHand [rank] == 4)
		{
			four == TRUE;
		}
		if (ranksinHand [rank] == 3)
		{
			three == TRUE;
		}
		if (ranksinHand [rank] == 2)
		{
			pairs ++;
		}
	}
        if (straight && flush)
		{
			printf("Straight Flush\n\n");
			return (10);
		}
		else if (four)
		{
            printf ("Four of a Kind\n\n");
            return (8);
		}
		else if (three && pairs == 1)
		{
            printf ("Full House\n\n");
            return (8);
		}
		else if (flush)
		{
			printf ("Flush\n\n");
			return (5);
		}
		else if (straight)
		{
			printf ("Straight\n\n");
			return (4);
		}
		else if (three)
		{
			printf ("Three of a Kind\n\n");
			return (3);
		}
		else if (pairs == 2)
		{
			printf ("Two Pairs\n\n");
			return (2);
		}
		else if (pairs == 1)
		{
			printf ("Pair\n\n");
			return (1);
		}
		else
		{
			printf ("High Card\n\n");
			return (0);
		}
}

//this function looks through each of the five cards and asks the user if they want a replacement card or not

void getFinalHand (int cardRank [], int cardSuit [], int finalRank [], int finalSuit [], int ranksinHand [], int suitsinHand [])
{
    int i, j, cardDup;
    char suit, rank, ans;

    for (i = 0; i < RANK; ++i)
	{
        suit = getSuit (cardSuit [i]);
        rank = getRank (cardRank [i]);
        printf ("\nDo you want to keep card #%d: %c%c?\n", i + 1, rank, suit);
        scanf ("%c", &ans);
		if (toupper (ans) == 'Y')
		{
            finalRank [i] = cardRank [i];
            finalSuit [i] = cardSuit [i];
            ranksinHand[finalRank [i]]++;
            suitsinHand [finalSuit[i]]++;
            continue;
		}
		else if (toupper (ans) == 'N')
		{
			cardDup = 0;
			do
			{
                cardDup = 0;
                finalRank [i] = (rand() % SUITE);
                finalSuit [i] = (rand() % FACES);

                //first check your new card against the 5 original cards to avoid duplication

                for (j = 0; j < RANK; j++)
				{
                    if ((finalRank [i] == cardRank [j]) && (finalSuit [i] == cardSuit [j]))
					{
						cardDup = 1;
					}
				}

				//next check the new cards against the any newly drawn cards to avoid duplication

                for (j = 0; j < i; j++)
				{
					if ((finalRank [i] == finalRank [j]) && (finalSuit [i] == finalSuit [j]))
					{
						cardDup = 1;
					}
				}
			}
			while (cardDup == 1);
			ranksinHand [finalRank[i]]++;
			suitsinHand [finalSuit[i]]++;
		}
	}
}

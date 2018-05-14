/*
* XINYU HADRIAN HU
* 500194233
* 17/02/2018
* RYERSON UNIVERSITY
* CPS 125
* FIBONACCI SERIES USING WHILE AND FOR LOOPS
*/

//including preprocessor directives >>

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

//defining MACROs >>

#define SPACE printf("\n");
#define PI 3.14159
#define LINE printf("--------------------------------------------------------------------------------------");
#define MAX 5000
#define SLS SPACE; LINE; SPACE;
#define TRUE 1
#define FALSE 0
#define ALT (-1)
#define FIBSEQ 	printf("i\tFibonacci Number\n"); SPACE;

//calling and defining functions necessary for this program >>

void swap (long long *xp, long long *yq)
{
	//this function swaps two values >>

	long long temp;
	temp = *xp;
	*xp = *yq;
	*yq = *xp;
}

long long int fib_interval (long long int fib[], long long int min_fib, long long int max_fib)
{
	//this interval finds and prints out the Fibonacci numbers in an interval of a lower and upper bound >>


}

long long int fib_primes_interval (long long int fib [], long long int num)
{
    //this function finds the prime numbers in the Fibonacci Series up to a given number

    int prime_counter = 1;
    int prime_loc = 1;
    int non_prime_counter = 1;
    int non_prime_loc = 1;
    int flag;
    int i, j;

	for (i = 2; fib [i] <= num; ++i)
	{
	fib[i] = fib [i - 1] + fib [i - 2];
		if (fib [i] > num)
		{
			break;
		}
		fib [j] = fib [i];
		for (j = 2; fib [j] <= num / 2; ++j)
		{
			if (fib [j] % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("\tThis number is a Fibonacci Prime.");
			++prime_counter;
		}
		else if (flag != 0)
		{
			++non_prime_counter;
		}

	}
    return fib_primes_interval (fib, num);
}

int main (int argc, char *argv[])
{

	//declaring variables for arrays and loops >>

	long long int fib [MAX];
	int i = 2, j, k;
	long long int limit = 0;

	//declaring variables for calculation >>

    long long int num;
	int fib_term;
    long long int fib_sum = 0;
    float fib_inv_sum = 2.00;
    long long int fib_alt_sum = 0;
    long long int fib_num;

    //initial values of Fibonacci Series >>

    fib[0] = 0, fib [1] = 1;

    //user input >>

	SPACE;
    printf("Enter a number >> ");
    scanf("%llu", &num);
    SPACE;
    printf("You entered >> %llu", num);
    SLS;

    //output the results >>

	printf("Start of Forward Fibonacci Series using While Loop >>");
	SLS;

	//using while loop >>
	FIBSEQ;
	printf("1.\t%llu\n2.\t%llu\n", fib [0], fib [1]);
	i = 2;
    while (limit == 0)
	{
		fib[i] = fib [i - 1] + fib [i - 2];
		if (fib [i] >= num)
		{
			break;
		}
        printf("%d.\t%llu\n", (i + 1), fib [i]);
		// calculates sum of Fibonacci Series values up to num >>
		fib_sum += fib [i];
		// calculates the alternating series sum of the Fibonacci Series up to num >>
		fib_alt_sum += (pow(ALT, i + 1))*fib [i];
		// calculates the inverse sum of the Fibonacci Series up to num >>
		fib_inv_sum += 1 / ((float) fib [i]);
        //
        ++i;
	}

	//using for loop >>
	SLS;

	//user input
	printf("Enter the desired number of terms >> ");
	scanf("%llu", &fib_term);
	printf("\nYou entered >> The %llu Fibonacci Term.\n", fib_term);

	SLS;
	printf("Start of Forward Fibonacci Series using For Loop >>");
	SLS;
	FIBSEQ;
	printf("1.\t%llu\n2.\t%llu\n", fib [0], fib [1]);
    for (i = 2; i < fib_term; ++i)
	{
		fib[i] = fib [i - 1] + fib [i - 2];
		if (i > fib_term)
		{
			break;
		}
		printf("%d.\t%llu\n", (i + 1), fib [i]);
		// calculates sum of Fibonacci Series values up to num >>
		fib_sum += fib [i];
		// calculates the alternating series sum of the Fibonacci Series up to num >>
		fib_alt_sum += (pow(ALT, i + 1))*fib [i];
		// calculates the inverse sum of the Fibonacci Series up to num >>
		fib_inv_sum += 1 / ((float) fib [i]);
        //
	}

	return (0);
}

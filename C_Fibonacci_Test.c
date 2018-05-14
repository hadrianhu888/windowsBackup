//including preprocessor directives

#include <stdio.h>

//defining MACROs

#define PI 3.14159
#define MAX 5000
#define FIBONACCISERIES fprintf(fibonacci_results, "1.\t%.0lf\n2.\t%.0lf\n", fibonacci [0], fibonacci [1]);

int main (int argc, char *argv[])
{
	//declaring variables

	FILE *fibonacci_results;
	fibonacci_results = fopen ("fibonacci_results.txt", "w");

	double num;
	double fibonacci[MAX];
	int i = 2;
	double limit = 0;

	//user input

	printf("\nEnter a number >> ");
	scanf("%lf", &num);
	fprintf(fibonacci_results, "\nYou entered >> %.0lf.\n\n", num);

	//initial values of fibonacci series

	fibonacci [0] = 0;
	fibonacci [1] = 1;

	//output

	fprintf(fibonacci_results, "\nFibonacci Series up to %.0lf using While Loop>> \n\n", num);

	FIBONACCISERIES;

	//printing out the results with while loop

	while (limit == 0)
	{
		fibonacci [i] = fibonacci [i - 1] + fibonacci [i - 2];
		if (fibonacci [i] > num)
		{
			break;
		}
		fprintf(fibonacci_results, "%d.\t%.0lf\n", i + 1, fibonacci [i]);
		++i;
	}

	//with for loop

	fprintf(fibonacci_results, "\nFibonacci Series up to %.0lf using For Loop>> \n\n", num);

	FIBONACCISERIES;

	for(i = 2; fibonacci [i] <= num; ++i)
	{
		fibonacci [i] = fibonacci [i - 1] + fibonacci [i - 2];
		fprintf(fibonacci_results, "%d.\t%.0lf\n", i + 1, fibonacci [i]);
	}

	//with do while loop

	fprintf(fibonacci_results, "\nFibonacci Series up to %.0lf using Do While Loop>> \n\n", num);

	FIBONACCISERIES;

	//reset initial value of index value

	i = 2;

	do
	{
		fibonacci [i] = fibonacci [i - 1] + fibonacci [i - 2];
		fprintf(fibonacci_results, "%d.\t%.0lf\n", i + 1, fibonacci [i]);
		++i;

	} while (fibonacci [i] <= num);


	/*****************************************************************
	double low, high;

	printf("\nEnter the lower bound >> ");
	scanf("%lf", &low);
	printf("\nEnter the higher bound >> ");
	scanf("%lf", &high);
	printf("\nLow >> %.0lf\nHigh >> %.0lf\n", low, high);

	i = 2;

	do
	{
		fibonacci [i] = fibonacci [i - 1] + fibonacci [i - 2];
		printf("%d.\t%.0lf\n", i + 1, fibonacci [i]);
		++i;

	} while (fibonacci [i] >= low && fibonacci [i] <= high);
	*****************************************************************/

	//close the file

	fclose(fibonacci_results);

	return (0);
}



//including preprocessor directives
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//defining MACROs
#define MAX 5000

int main (int argc, char *argv[])
{
    //declaring variables

    FILE *output;

    output = fopen ("result.txt", "w");

    int i;
    long long fib[MAX];
    long long limit = 0;
    long long num;
    int term;
    long long lower, upper;

    fib [0] = 0, fib [1] = 1;
    i = 2;

    //using while loop

    printf("\nEnter the upper boundary of the Fibonacci Series >> ");
    scanf("%llu", &num);
    fprintf(output, "\nYou entered >> %llu", num);

    fprintf(output,"\n\nFibonacci Series up to %llu>> \n", num);

    fprintf(output,"1.\t%llu\n2.\t%llu\n", fib [0], fib [1]);

    //output

    while(limit == 0)
	{
		fib [i] = fib [i - 1] + fib [i - 2];
		if (fib [i] > num)
		{
			break;
		}
		fprintf(output,"%d.\t%llu\n", i + 1, fib [i]);
		++i;
	}

	//using for loop

	printf("Enter the desired Fibonacci Term >> ");
	scanf("%d", &term);
	fprintf(output,"\nYou entered >> %d.\n\n", term);

	//output

	fprintf(output,"Fibonacci Series up to %d term of the Fibonacci Series >> \n", term);

	fprintf(output,"1.\t%llu\n2.\t%llu\n", fib [0], fib [1]);
	for(i = 2; i < term; ++i)
	{
		fib [i] = fib [i - 1] + fib [i - 2];
		if (i > term)
		{
			break;
		}
		fprintf(output,"%d.\t%llu\n", i + 1, fib [i]);
	}

	//print out the Fibonacci Series in an interval

	printf("\n\nEnter the lower and upper boundaries >> ");
	printf("\nLower Boundary >> ");
	scanf("%llu", &lower);
	printf("\nUpper Boundary >> ");
	scanf("%llu", &upper);

	fprintf(output, "\nLower Boundary >> %llu\n\nUpper Boundary >> %llu\n\n", lower, upper);

	printf("\n\nFibonacci Series Between %llu and %llu\n\n", lower, upper);


	for (fib[i] > lower; fib[i] < upper; ++i)
	{
		if(fib [i] < lower)
		{
			break;
		}
		fib [i] = fib [i - 1] + fib [i - 2];
		printf("%d.\t%llu\n", i + 1, fib [i]);
		if (fib [i] > upper)
		{
			break;
		}
	}


	fclose(output);

	//end of program
	return (0);
}

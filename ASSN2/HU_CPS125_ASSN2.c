#include <stdio.h>
#include <math.h>
#define PI 3.14159

//Xinyu Hadrian Hu
//500194233
//12/01/2018
//Assignment 2
//CPS 125 2018

int
main (void)
{
	//part 1

	int a = 3, b = 4;

	//e is a variable that was not used anywhere

	double f = 4, c, d;

	//convert int to double where a and b exists in the functions below

	d = (double) (a + b);
	c = (double) a / (f - (double) b);
	printf ("The value of d is %.3lf.\n", d);

	//end the program

	//---------------------------------

	//part 2

	//initialize a value that the user can enter

	double num;

	printf("\nEnter a number: ");

	scanf("%lf", &num);

    printf("\n\nThe value you entered is: %.3lf rounded to 3 decimal places or \n%.2lf rounded to 2 decimal places.", num, num);

    //---------------------------------------------------------

    //part 3 - perimeter of an ellipse

    //initialize short and long radius

    double l , s;

    //initialize perimeter;

    double p;

    //input values

    printf("\n\n\Enter the short radius: ");
    scanf("%lf", &s);
    printf("\n\nEnter the long radius: ");
    scanf("%lf", &l);

    //if l < s
    //check to make sure long radius is not smaller than short radius

    if(l < s)
    {
        double temp;

        temp = l;
        l = s;
        s = temp;
    }

    //calculates perimeter

    //calculate product of short and long

    double prod;

    prod = l * s;

    //calculate sum of short and long

    double sum;

    sum = l + s;

    //formula for short and long radius to determine perimeter of ellipse

    p = (4*sum*pow((PI/4),((4*prod)/(pow(sum, 2)))));

    //prints out the result of the perimeter

    printf("\n\nThe perimeter of the ellipse with\nshort radius of : %.3lf and\nlong radius of: %.3lf\nhas a perimeter of: %.3lf units.\n\n\n", s, l, p);

    //-------------------------------------------------------------------------

    //part 4

    /*
    What is the difference between char and Char?

    char is a character data type. Char is a user-defined variable

    What is displayed by printf ("%d", 3/4); ?

    0

    Is printf ("%f", 50); valid?

    Yes. 50 is a float value.

    If you omit the ; at the end of a C statement, is it still working?

    No. It produces a run-time error.

    What is the difference between %f and %lf?

    %f = float, %lf = double or long float

    What happens when you attempt a division by zero in C?

    NaN and run time error

    Is the expression 35%15.3 valid?

    No - it is a mod statement

    Is there a difference between starting your program with main() instead of int main (void)?

    No

    What happens if you try to display an integer between 0 and 255 with a %c placeholder?

    It displays the address of the integer in memory

    Are the expressions 5/3, 5%3, 5.0/3 exactly the same?

    No. 5/3 produces an integer, 5%3 is a mod, and 5.0/3 is a double

    ----------------------------------------------------------------------------------------

    //part 5

    Integer variables are defined by "int" and are of data type %d, while double is defined by "double" and are of the data type %lf.

    */

    return (0);
}

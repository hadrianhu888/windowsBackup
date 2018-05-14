#include <stdio.h>
#include <math.h>
#include <string.h>

//declare commonly used preprocessor directives

#define PI 3.14159
#define SPACE printf("\n\n");

//declare functions

long int factorial (int n);
float stirling (float N);
int absolute (int n);

int main (void){

    //define variable

    int n;

    float per_err, f, s;

    //lets the user enter the value

    printf("\n\n-------------------Factorial Calculator with Stirling Approximation-------------------");
    printf("\n\nEnter a positive number: ");
    scanf("%d", &n);

    //check if entered n variable is > 0 or <= 0

    if(n < 0){
        absolute(n);
        factorial(n);
    }
    else {
        factorial(n);
    }

    //displays the answers in traditional form of the Factorial and the Stirling Approximation

    printf("\n\nThe Normal Factorial of %d! is: %.2ld.", abs(n), factorial(n));
    printf("\n\nThe Stirling Approximation of %d! is: %.6lf.", n, stirling(n));

    //change factorial and Stirling to variables f and s respectively

    f = (float) factorial(n);
    s = stirling(n);

    //calculate percentage error

    per_err = (((f - s)/f)*100.00);

    //print out the % error value

    printf("\n\nThe percentage error between Stirling Approximation and Factorial is: %.6f%%.", per_err);

    SPACE;

return(0);
}
long int factorial(int n){

    //function to calculate factorial by traditional means

    if (n < 0)
        return abs(n)
        * factorial(abs(n) - 1);
    else if (n >= 1)
        return n * factorial(n - 1);
    else
        return 1;
}
float stirling (float N){

    //using the Stirling Approximation

    float st_app = pow(N, N) * exp(-N) * sqrt((2 * N + 1/3)*PI);

    return st_app;

}
int absolute(int n){

    //if n is negative, return the absolute value of n

    if (n < 0)
        return abs(n);
    else
        return n;
}



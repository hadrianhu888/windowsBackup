#include <stdio.h>

int main (int argc, char * argv [])
{

    int age = 15;
    int * Page = 20;
    /**Page = &age;
    Page = &age + age;
    Page = ++age;
    Page = age++;**/

    printf ("Age = %d\n\n", age);
    printf ("* Page = %d\n\n", * Page);

	return (0);
}

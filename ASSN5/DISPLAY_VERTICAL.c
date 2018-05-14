#include <stdio.h>
#include <stdlib.h>

void displayvert(char str[]);
void getgcd(int num);

int main()
{
  char input[11]; // additional character added for \0

  printf("Please enter a value up to 10 digits: ");
  scanf("%s", input);
  displayvert(input);
  getgcd(atoi(input));

  return 0;
}

void displayvert(char str[])
{
  int i;

  for (i = 0; str[i] != '\0'; ++i) {
    printf("%c\n", str[i]);
  }
}

void getgcd(int num)
{
  int i, gcd;

  // remember, you can't do x % 0!
  for (i = 1; i < num; i++) {
    if ((num % i) == 0 ) {
      gcd = i;
    }
  }

  printf("The greatest common divisor is: %d\n", gcd);
}

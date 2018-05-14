#include <stdio.h>
#include <stdlib.h>
int toronto (int x)
{
	int w;
	if (x == 0)
		w = 1;
	else w = toronto (x-1); // 2 - 1 = 1
	return (w);
}

int main (void)
{
	int a = 2;
	printf ("%d", toronto (a));
	return (0);
}

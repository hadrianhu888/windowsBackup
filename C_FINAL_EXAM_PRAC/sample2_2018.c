#include <stdio.h>

int cps (int mark, int *num)
{
	int gp;
	gp = mark - 5; // 10 - 5 = 5
	*num = gp + mark; //10 + 5 = 15
	return (gp);
}
int
main (void)
{
	int tt=10, vv;
	tt = cps (tt, &vv); //15 + 5 = 20
	printf ("%d", tt+vv);
	return (0);
}

//output is 20

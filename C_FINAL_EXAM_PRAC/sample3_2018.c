#include <stdio.h>
int cps (int mark)
{
	mark = mark-3; // 12 - 3 = 9
	return (mark);
}
int ckcs (int num)
{
	num= cps(num) /2; // 9/2 = 4
	return (num);
}
int
main (void)
{
	int t=12;
	t = ckcs (t)-1; // 4 - 1 = 3
	printf ("%d", t);
	return (0);
}

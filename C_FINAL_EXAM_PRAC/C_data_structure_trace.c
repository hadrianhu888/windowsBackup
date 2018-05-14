#include <stdio.h>
#include <string.h>
int main (int argc, char * argv [ ])
{
	struct gospel
	{
		int num;
		char mess1 [50];
		char mess2 [50];
	} m;

	m.num = 1;
	strcpy (m.mess1, "If all that you have is a hammer");
	strcpy (m.mess2, "Everything looks like a nail.");

    printf ("\n%u %u  %u\n." &m.num, m.mess1, m.mess2);

    /** error **/

	return (0);
}

#include <stdio.h>
int main (void)
{
	int scalar_product, n, k;
	int v1[]={2,3,1};
	int v2[]={1,2,4};
	scalar_product = 0;
	n=3;
	for (k=0; k<n; ++k)
		scalar_product = scalar_product + v1[k]*v2[k]; // 2 * 1 + 3 * 2 + 1 * 4 = 2 + 6 + 4 = 12
	printf ("The scalar product is: %d.", scalar_product);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

#define FILE_STRING 100

struct productOrder

{
	long long int products;
	long long int items;
	float item_cost;
};

int main (int argc, char * argv [ ])
{
    FILE * ptrFile;
    char fileName [FILE_STRING];
    int size;
    int i, j, k;

    struct productOrder ** list;

    printf ("\nEnter the name of your file >> ");
    scanf ("%s", fileName);
    printf ("\nName of your file >. %s\n\n", fileName);

    printf ("\nEnter how many entries you want to add >> ");
    scanf ("%d", &size);
    printf ("\nSize of your array >> %d.\n\n", size);

    list = (struct productOrder **) calloc (size, sizeof (struct productOrder *));
    if (list == NULL)
	{
		printf ("\nNOT ENOUGH MEMORY!\n");
		exit (1);
	}

    for(i = 0; i < size; ++i)
	{
        printf ("\nEnter how many products you want >> ");
        scanf ("%llu", &list->products);
        printf ("You entered >> %llu products.\n\n", list->products);
        list [i] = (struct productOrder *) calloc (list->products, sizeof (struct productOrder));
        if (list == NULL)
		{
			printf ("\nNOT ENOUGH MEMORY!\n");
			exit (1);
		}
        for (j = 0; j < list->products; ++j)
		{
			printf ("\nEnter how many units >> ");
			scanf ("%llu", &list->items);
			printf ("\nEnter cost per unit >> ");
			scanf ("%f", &list->item_cost);
			printf ("\nItems: %llu\tUnit Cost: $%.2f\n", list->items, list->item_cost);
		}
	}

	for (i = 0; i < size; i++)
	{
		free (list [i]);
	}
	free (list);

	fclose (ptrFile);

    return (0);
}

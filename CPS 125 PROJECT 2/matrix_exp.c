#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NAME 50
#define MIN 2
#define MAX 200

int main (int argc, char * argv [ ])
{
    FILE * ptrTest;
    char ptrName [NAME];
    int row, col;
	int i, j;
    double ptrMat [MAX] [MAX];
    double matV;
    char line;
    int count = 0;

    VALIDATE:

    printf ("Enter the name of your file >> ");
    scanf ("%s", &ptrName);
    ptrTest = fopen (ptrName, "r");
    if (ptrTest == NULL)
	{
        printf ("The file does not exist. Please enter a valid file name.\n");
        goto VALIDATE;
	}
	printf ("\nFile Name >> %s.\n\n", ptrName);

	fscanf (ptrTest, "%d %d", &row, &col);
	printf ("Row >> %d\t Col >> %d\n\n", row, col);

	for (line = getc (ptrTest); line != EOF; line = getc (ptrTest));
	{
		if (line == '\n')
		{
			++count;
		}
	}

	fclose (ptrTest);

	count = 0;
	fopen (ptrTest, "r");
	printf ("Matrix of %d X %d Dimensions >> \n\n", row, col);
	double status = fscanf (ptrTest, "%lf ", &matV);
    while ((fscanf (ptrTest, "%lf ", &matV)) != EOF);
    {
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < col; ++j)
			{
				fscanf (ptrTest, "%lf ", &matV);
				ptrMat [i] [j] = matV;
				printf ("%.3lf\t", ptrMat [i] [j]);
				if (j > col)
				{
					break;
				}
			}
			if (i > row)
			{
				break;
			}
			fscanf (ptrTest, "\n");
			printf ("\n");
		}
		fscanf (ptrTest, "%lf ", &matV);
		printf ("\n");
    }
    fclose (ptrTest);


    /**while ((fscanf (ptrTest, "\n"))!= EOF)
	{
		fscanf (ptrTest, "\n");
		break;
	}

	fclose (ptrTest);**/

	return (0);
}

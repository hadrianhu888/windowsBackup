/*------------------------------------*
 * Xinyu Hadrian Hu                   *
 * 500194233                          *
 * CPS 125 ASSN 5                     *
 * 20/01/2018                         *
 *------------------------------------*/

//preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//defining MACROS

#define PI 3.14159
#define MAX 5
#define SPACE printf("\n\n");

int main (int argc, char *argv[]) {

    int beach_num[MAX], i, j;

    for(i = 0; i < MAX; i++) {
        printf("\n\nEnter a beach number >> ", (i+1), MAX);
        scanf("%d", &beach_num[i]);
        printf("\nYou entered: %d.\n", beach_num[i]);
    }

    /*prints out the beach numbers in a list:*/

    printf("\n\nBeach Numbers List >> \n\n");

    for(j = 0; j < MAX; j++) {
        printf("%d. Beach Number:: %d.\n\n", (j+1), beach_num[j]);

        //j + 1 to make the cardinal counting numbers start from 1
    }

    //TODO:

    //number of samples still need to work

    //array to store number of organisms per 100 mL should also be made to work

    int num_samples, m, n, s, k;
    int b_count[s];

    for(m = 0; m < MAX; m++) {
            for(k = 0 ; k < num_samples; k++) {

                printf("\n\nEnter bacteria parts per 100 ml >> ", (k+1), b_count[k]);
                scanf("%d\n", &b_count[k]);

            }
        printf("\n\nEnter number of samples taken at beach number %d >> ", beach_num[m], MAX);
        scanf("%d", &num_samples);
    }

    return (0);

}







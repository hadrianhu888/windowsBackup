/* 
 * ----------------------------------------------------------------
 * 
 * XINYU HADRIAN HU
 * 500194233
 * 18/03/2018
 * CPS 125
 * ASSN 7 
 * NORM AND STANDARDIZATION OF A RANDOM FILE FROM DISK, 
 * AND FREQUENCY DISTRIBUTION COUNTER IN STEPS OF 10
 * 
 * ----------------------------------------------------------------
 * 
 * ASSN_7_NORM_STD.c
 * 
 * Copyright 2018 Owner <Owner@DESKTOP-VP905B6>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/*
 * including preprocessor directives 
 */ 

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <ctype.h> 
#include <windows.h> 
#include <time.h> 

/* 
 * defining user-defined MACROS 
 */
 
#define PI 3.14159
#define SPACE printf("\n"); 
#define D_SPACE printf("\n\n"); 
#define TRUE 1 
#define FALSE 0 
#define LINE printf("---------------------------------------------------"); 
#define MAX 5000
#define FILE_MAX 1000

/* 
 * defining prototype functions 
 */ 
 
 //assigning global variables as needed 
 
 char file_name [FILE_MAX]; 
 
 void title (); 
 
 void input (); 

int main(int argc, char *argv [])
{
	
	title(); 
	
	//get user input 
	
	input (); 
	
	
	return 0;
}

void title ()
{
	//prints out the title of this C program 
	
	LINE; 
	SPACE; 
	printf("NORMALIZATION AND STANDARDIZATION OF FILE DATA"); 
	SPACE; 
	LINE; 
	SPACE; 
}

void input ()
{
	//gets user input options 
	
	char file_name [FILE_MAX]; 
	double arr_data [MAX];
	double value; 
	
	//double *array_vector; 
	
	int i; 
	
	FILE *ptr_file; 
	
	char line; 
	int count = 0; 
	int size; 
	
	FILENAME: 
	D_SPACE; 
	printf("Enter the name of your file >> "); 
	scanf ("%s", file_name); 
	
	if (fopen (file_name, "r") != NULL)
	{
		printf("\aError!\n\n"); 
		goto FILENAME; 
	}
	
	ptr_file = fopen (file_name, "r+"); 
	
	for (line = getc (ptr_file); line != EOF; line = getc (ptr_file))
	{
		if (line == '\n' || line == '\t' || line == ' ')
		{
			++count; 
		
		}
	}
	
	//array_vector = malloc(arr_data, sizeof (double*)); 
	
	//D_SPACE; 
	//printf ("Size >> %d", count); 
	
	size = count; 
		
	
	D_SPACE; 
	printf("This some bs: %d", count);
	
	//printf ("Size of THE Array >> %d\n\n", size); 
	
	/*
	 * Displays the values in the file on the screen -- 
	 * THIS IS WHERE THE FILE ONLY DISPLAYS ZEROES INSTEAD OF THE ACTUAL ARRAY DATA
	 */ 
	
	printf ("\nArray Data >> \n\n"); 
	printf ("Index\t\t\tValue\n\n"); 
	
	for (i = 0; i <= count - 1; i++)
	{ 
		//storing each value into the array index - this block of code is not working
		
			//arr_data[i] = value; 
			//printf ("[%d] of [%d] >>\t\t%.3lf\n", (i + 1), size, arr_data[i]); 
			//++i; 
			//fscanf(ptr_file, "%lf\n", &value); 
		
		//while (line != EOF)
		//{
			
			//fscanf (ptr_file,  "%lf\n", &arr_data[i]); 
			////value = arr_data[i];
			////arr_data [i] = value;
			//printf("\n%lf", arr_data[i]);   
			//i++; 	
			
			////fgets (arr_data, MAX, ptr_file); 
			////puts (arr_data); 
					
		//}

		//fscanf (ptr_file, "%lf\n", &arr_data[i]); 
		//printf ("[%d] of [%d] >>\t\t%.3lf\n", (i + 1), size, arr_data[i]); 
		
	}
		
	fclose (ptr_file); 
	
}

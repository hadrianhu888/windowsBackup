/* --------------------------------------------
 * XINYU HADRIAN HU 
 * 500194233 
 * CPS 125
 * MIDTERM TEST SAMPLE SOLUTION 
 * 
 * 18.03.2018
 * --------------------------------------------
 * C_buses.c
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
 
//preprocessor directives 

#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <time.h> 

//defining MACROs to be used throughout this program 

#define PI 3.14159
#define TRUE 1 
#define FALSE 0 
#define PHI 0.618
#define IHP 1.618
#define SPACE printf("\n"); 
#define D_SPACE printf("\n\n"); 

//function prototypes of functions to be called 

int full_buses (int bus_capacity, int passengers); 

int semi_full_buses (int bus_capacity, int passengers); 

int main(int argc, char **argv)
{
	//declare variables 
	
	int bus_capacity; 
	int full_buses_number; 
	int semi_full_buses_number; 
	int passengers; 
	
	printf("Bus Capacity Calculator");
	D_SPACE; 
	
	//user input 
	
	printf("Enter the carrying capacity per bus >> "); 
	scanf ("%d", &bus_capacity); 
	printf ("\nBus Capacity >> %d", bus_capacity); 
	D_SPACE; 
	
	//find out how many passengers will be carried 
	
	printf ("Enter the number of expected passengers >> "); 
	scanf("%d", &passengers); 
	printf ("\nPassengers >> %d", passengers); 
	
	//calls the functions 
	
	full_buses_number = full_buses (bus_capacity, passengers);
	
	semi_full_buses_number = semi_full_buses (bus_capacity, passengers);
	
	D_SPACE; 
	
	//print out the results
	
	if (passengers % bus_capacity == 0)
	{
		printf("Remaining Passengers in the Last %d Bus >> %d passengers.", full_buses_number, semi_full_buses_number); 
		D_SPACE; 
		printf("Full Buses >> %d",  full_buses_number); 
		D_SPACE; 
		printf ("Total Buses >> %d" , full_buses_number); 
	}
	else if (passengers % bus_capacity != 0)
	{
		printf("Remaining Passengers in the Last Bus # %d >> %d passengers.", full_buses_number + 1, semi_full_buses_number); 
		D_SPACE; 
		printf("Full Buses >> %d",  full_buses_number); 
		D_SPACE; 
		printf ("Total Buses >> %d" , full_buses_number + 1); 
	}
		
	return 0;
}

int full_buses (int bus_capacity, int passengers)
	
//finds full buses 

{
	int full_buses; 	
	full_buses = passengers / bus_capacity; 	
	return (full_buses); 
}

int semi_full_buses (int bus_capacity, int passengers)

//determines the number of people in the last remaining bus 

{
	int semi_full_buses; 	
	semi_full_buses = passengers % bus_capacity; 	
	return (semi_full_buses); 
	
}

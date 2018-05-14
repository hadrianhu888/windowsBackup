/*
 * Geany_test_program.c
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
 * Xinyu Hadrian Hu
 * 15/01/2018
 * CPS 125 
 * Digital Computation and Programming 
 * 
 */


#include <stdio.h>

//define preprocessor MACRO 

#define INDEX 3

int main(int argc, char **argv) {
	//declare variables 
	
	float n1, n2, n3, sum; 
	
	//declare the average variable as a double 
	
	double avg; 
	
	FILE *res; 
	res = fopen("res.txt", "w"); 
	
	printf("\n\nPlease enter three numbers: "); 
	scanf("%f %f %f", &n1, &n2, &n3); 
	
	//displays what the user entered
	
	printf("\n\nThe three numbers are: %.3f %.3f %.3f.", n1, n2, n3); 
	
	//find the sum 
	
	sum = n1 + n2 + n3; 
	
	//find the average
	
	avg = (double) sum / (double) INDEX; 
	
	//print out the result 
	
	printf("\n\nThe average of the three numbers is: %.3lf", avg); 
	
	//print to .txt file 
	
	fprintf(res, "The three numbers entered are: %.3f, %.3f, and %.3f", n1, n2, n3); 
	fprintf(res, "\n\nThe average of the three numbers is: %.3lf", avg); 
	
	fclose(res); 
	
	return 0;
}


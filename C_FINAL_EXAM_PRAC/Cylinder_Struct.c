//preprocessors

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

//macros

#define PI 3.14159
#define TRUE 1
#define FALSE 0

typedef struct shape
{
	float line;
	float radius;
	float areacircle;
	float areacylinder;
	float volumecylinder;

} geometry;

geometry a_circ (geometry r);
geometry a_cyl (geometry a, geometry l);
geometry vol_cyl (geometry a, geometry l);

int main ( int argc, char * argv [ ] )
{
    geometry line, rad, area_circ, area_cyl, v_cyl;

    printf ("\nPlease enter the length >> ");
    scanf ("%f", &line.line);

    printf ("\nPlease enter the radius >> ");
    scanf ("%f", &rad.radius);

    printf ("\n\nLength\tRadius\n\n");
    printf ("%.3f\t%.3f\n\n", line.line, rad.radius);

	area_circ = a_circ (rad);
	area_cyl = a_cyl (rad, line);
	v_cyl = vol_cyl(rad, line);

	return (0);
}

geometry a_circ (geometry r)
{
	geometry area;
	area.areacircle = PI * pow (r.radius, 2);

	printf ("The area of the circle is >> %.3f unit squared.\n\n", area.areacircle);
	return (area);
}
geometry a_cyl (geometry r, geometry l)
{
	geometry a_circles;
	geometry surface_area;
	geometry cylinder_surface_area;

	a_circles.areacircle = 2 * PI * pow (r.radius, 2);

    surface_area.areacylinder = 2 * PI * r.radius * l.line;

    cylinder_surface_area.areacylinder = surface_area.areacylinder + a_circles.areacircle;

    printf ("The cylinder's surface area is >> %.3f unit squared.\n\n", cylinder_surface_area.areacylinder);

    return (cylinder_surface_area);
}
geometry vol_cyl (geometry r, geometry l)
{
    geometry a_circle;
    geometry volume_cylinder;

    a_circle.areacircle = PI * pow (r.radius, 2);
    volume_cylinder.volumecylinder = a_circle.areacircle * l.line;

    printf ("The volume of the cylinder is >> %.3f unit cubed.\n\n", volume_cylinder.volumecylinder);

    return (volume_cylinder);
}




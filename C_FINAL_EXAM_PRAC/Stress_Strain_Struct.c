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

typedef struct strength
{

	float p;
	float d;
	float stress;
	float strain;
	float area;
	double modulus;

} strength;

strength area (strength d);
strength stress (strength p, strength area);
strength strain_c (strength p, strength d, strength elastic_mod);

int main (int argc, char * argv [ ])
{
    strength diam_d, load_p, area_pressure, stress_calc, strain_calc, mod;

    //let the user enter load and diameter

    printf ("\n\nPlease enter the load in N >> ");
    scanf ("%f", &load_p.p);

    printf ("\n\nPlease enter the diameter in meter >> ");
    scanf ("%f", &diam_d.d);

    printf ("\n\nPlease enter the modulus of elasticity >> ");
    scanf ("%lf", &mod.modulus);

    printf ("\n\nLoad\t\t\tDiameter\t\t\tModulus\n\n");
    printf ("%.3f N\t\t%.3f m\t\t\t%.3lf\n\n", load_p.p, diam_d.d, mod.modulus);

    //call functions

    area_pressure = area (diam_d);

    stress_calc = stress (load_p, diam_d);

    strain_calc = strain_c (load_p, diam_d, mod);

    //print out the results

    printf ("Area >>\t\t%.3f m-sqr.", area_pressure.area);
    printf ("\n\nStress >>\t%.3f Pa.", stress_calc.stress);
    printf ("\n\nStrain >>\t%.3f MPa.\n\n", strain_calc.strain);

	return (0);
}
//calculate the area
strength area (strength d)
{
    strength a;

    a.area = (PI * pow (d.d, 2)) / 4.0;

    return (a);
}
//calculate the stress
strength stress (strength p, strength d)
{
    strength a;
    strength stress_val;
    a = area (d);

    stress_val.stress = p.p / a.area;

	return (stress_val);

}
//calculate the strain
strength strain_c (strength p, strength d, strength elastic_mod)
{
    strength s;
    strength strain_val;

    s = stress (p, d);

    strain_val.strain = s.stress / elastic_mod.modulus;

    return (strain_val);
}

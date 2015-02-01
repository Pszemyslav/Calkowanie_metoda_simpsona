#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double calnum(double a, double b, int n, double (*f) (double))
{
	int i;

	double h=(b-a)/n;
	double calka=0;

	for(i=0;i<n;i++)
	{	
		double x1 = a+i*h;	/*współrzędne podprzedzialow*/
		double x2 = a+(i+1)*h;
		double sr = (x1+x2)/2;		/*srodek przedzialu*/
		/*W tym programie "h" jest to szerokość całego podprzedziału, a nie jego połowa. Stąd we wzorze obok dzielę przez 6, a nie przez 3*/
		calka = calka + h*( f(x1) + 4*f(sr) + f(x2) )/6;  
	}
}

int main(int argc, char *argv[])
{       
	double a = argc >1 ? atof(argv[1]) : 0;
	double b = argc >2 ? atof(argv[2]) : 10;
	int n = argc >3 ? atoi(argv[3]) : 100;
	double calka = calnum(a, b, n, sin);
	printf("%g\n",calka);
	return 0;
}

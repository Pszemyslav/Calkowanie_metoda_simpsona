#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


double f(double x)
{
	return 4*x*x*x - 3*x*x + 6*x - 10;
	}    /*funkcja podlegajaca calkowaniu. */


int main(int argc, char *argv[]) /*(a,b)-przedział, n-liczba podprzdzialow na które dzielimy przedzial */
{       
	double a= argc >1 ? atof(argv[1]) : 0;
	double b= argc >2 ? atof(argv[2]) : 10;
	int n =argc >3 ? atoi(argv[3]) : 100;
	int i;

	double h=(b-a)/n;
	double calka=0;

	for(i=0;i<n;i++)
	{	
		double x1 = a+i*h;	/*współrzędne podprzedzialow*/
		double x2 = a+(i+1)*h;
		double sr = (x1+x2)/2;		/*srodek przedzialu*/

		calka = calka + h*( f(x1) + 4*f(sr) + f(x2) )/6;  /*W tym programie "h" jest to szerokość całego podprzedziału, a nie jego połowa. Stąd we wzorze obok dzielę przez 6,a nie przez 3*/
		}
	printf("%g\n",calka);
	return 0;
	}

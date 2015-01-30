#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double f(double x)
{
	return 4*x*x*x - 3*x*x + 6*x - 10;
	}    /*funkcja podlegajaca calkowaniu. */
double calka_ozn(double x, double a, double b, double c)
{
	return a*x*x*x/3 + b*x*x/2 + c*x;
	}
int main(int argc, char *argv[]) /*(a,b)-przedział, n-liczba podprzdzialow na które dzielimy przedzial */
{       
	double a= argc >1 ? atof(argv[1]) : 0;
	double b= argc >2 ? atof(argv[2]) : 10;
	int n =argc >3 ? atoi(argv[3]) : 100;
	int i;
	double h=(b-a)/(n+1);
	double calka=0;
	for(i=0;i<n;i++)
	{	
		double x1 = a+i*h;	/*współrzędne podprzedzialow*/
		double x2 = a+(i+1)*h;
		double sr = (x1+x2)/2;		/*srodek przedzialu*/
		double wa = (f(x2)-f(x1) - (f(sr)-f(x1)) * (x2-x1)/(sr-x1)) / (x2*x2-x1*x1 - (sr*sr-x1*x1) * (x2-x1)/(sr-x1));
		double wb = (f(sr)-f(x1) - wa*(sr*sr-x1*x1)) / sr-x1;
		double wc = f(x1) - wa*x1*x1 - wb*x1;
		calka = calka + calka_ozn(x2, wa, wb, wc) - calka_ozn(x1, wa, wb, wc);
		}
	printf("%g\n",calka);
	return 0;
	}

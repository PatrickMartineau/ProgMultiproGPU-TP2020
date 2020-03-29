/*
This program will numerically compute the integral of
                  4/(1+x*x)
from 0 to 1.
History: Written by Tim Mattson, 11/99.
*/
#include <stdio.h>
#include "omp_repair.h"
// Nombre de bandes à calculer dans un quart de cercle
static long num_steps = 100000000; // 100 millions
double step;
int main ()
{
	  int i;
	  double x, pi, sum = 0.0;
	  double start_time, run_time;
		// largeur de la bande
	  step = 1.0/(double) num_steps;
		//mémorisation date initiale
	  start_time = omp_get_wtime();
		//Pour chaque itération, on calcule x et f(x) (et on l'ajoute immédiatement à sum)
	  for (i=1;i<= num_steps; i++){
		  x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }
		//pour obtenir l'aire on multiplie par la largeur de la bande soit step
		//ici, c'est fait de manière factorisée (1 multiplication au lieu de 100 Million)
	  pi = step * sum;
		//calcul du temps
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
}

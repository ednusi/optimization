#include <stdio.h>
#include <math.h>

typedef struct pointpair{
	double x;
	double y;
} pair_t;

double square(double x){return x*x+5;}
double randompoly(double x){return x*x*x+x*x*2+500-1*cos(x);}

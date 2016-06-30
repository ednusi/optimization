/* 
Edward Nusinovich
Given a function y = f(x) finds the nearest local minimum. 
Will only solve convex problems.
*/

#include "hillclimber.h"

/* Solves problem from R->R */
pair_t hillclimb(double (*function)(double), double guess){

	double cur = (*function)(guess); /* The initial value */
	double step = 0.0001;
	char done=0;
	
	do{
	
		double lstep = guess-step;
		double rstep = guess+step;
	
		double lval = (*function)(lstep);
		double rval = (*function)(rstep);
		
		double ldif = cur-lval;
		double rdif = cur-rval;
		
		if(ldif<0&&rdif<0||(ldif==0&&rdif==0)){
			done = 1; 
		}else if(ldif>rdif){
			cur = lval; guess = lstep;
		}else if(rdif>ldif || rdif==ldif){
			cur = rval; guess = rstep;
		}
	
	}while(!done);
	
	pair_t toreturn;
	toreturn.x = guess;
	toreturn.y = cur;
	return toreturn;
}

int main(){

	double(*func)(double) = randompoly; /* Set function to whatever you want to be minimized */ 
	double guess = 0.0; /* Set this to your guess for a local minimum */

	pair_t sol = hillclimb(func,guess);
	printf("The minimum is %f at %f.\n",sol.y,sol.x);

	return 0;
}

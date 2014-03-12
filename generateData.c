#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define E 2.7182818284
#define PI 3.1415926535

double function(double x, double y){
	return pow(E, x) * sin(x);
}


int main(){
	
	FILE *newF;
	newF = fopen("ex_sin.txt", "w+");
	//fprintf(newF, "%s\n", "400");
	fprintf(newF, "200\n");
	double y = 0;
	for(double x = -3; x < 6; x += 0.045){
			fprintf(newF, "%lf %lf\n", x,  function(x, y));
			y -= 0.1;
	}
}
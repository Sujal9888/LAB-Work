#include<stdio.h>
#include<math.h>
double function(double x){
	return x*x*x + x*x- 3*x -3;
}
int main(){
	double x1, x2, m;
	int itr=0;
	
	printf("\nTwo initial guess (x1,x2):");
	scanf("%lf %lf", &x1,&x2);
	if(function(x1)*function(x2)>=0){
		printf(" Invalid initial guess");
	}else{
		printf("\nBisection method of function x^3+x^2-3x-3\n");
		printf("\nIteration \t x1 \t 	  x2 \t	  	  m \t	  f(m) \n");
		while(fabs(x2-x1)>=0.0001){
			itr++;
			m=(x1+x2)/2;
			printf("\n%d \t	%.5lf \t %.5lf \t	%.5lf \t %.5lf",itr, x1, x2, m, function(m));
			if (function(x1)*function(m)<0){
				x2=m;
			}
			else{
				x1=m;
			}
		}
	} 
printf("\nRoot found at %lf",m);
	return 0;
}

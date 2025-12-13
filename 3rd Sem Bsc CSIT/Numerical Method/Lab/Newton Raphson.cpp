#include<stdio.h>
#include<math.h>
double f(double x){
	return x*x+ 4*x -9;
}
double fd(double x){
	return 2*x +4;
}
int main(){
	int itr=0;
	double x0, x1;
	printf("Enter initial Guess x0:");
	scanf("%lf",&x0);
	while(1){
		double fx=f(x0);
		double fdx=fd(x0);
	
		x1=x0-(fx/fdx);
		
		printf("\nIteration %d: x=%.5lf, f(x)=%.5lf ",itr+1, x0,fx);
	if(fabs(x1-x0)<0.0001){
		break;
	}
	x0=x1;
	itr++;
	}
	printf("\nRoot is found at %lf",x1);
return 0;
	
}

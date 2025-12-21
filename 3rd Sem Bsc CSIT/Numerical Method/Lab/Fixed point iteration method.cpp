#include <stdio.h>
#include <math.h>

double g(double x){
    return cbrt(3 + 3*x - x*x);
}

int main(){
    double x0, x1;
    int itr = 0;

    printf("\nEnter initial guess x0: ");
    scanf("%lf", &x0);

    printf("\nFixed Point Iteration for x^3 + x^2 - 3x - 3 = 0\n");
    printf("\n%-6s %-15s %-15s\n", "Iter", "Xn", "Xn+1");
    printf("------------------------------------------------\n");

    while(1){
        itr++;
        x1 = g(x0);

        printf("%-6d %-15.6lf %-15.6lf\n", itr, x0, x1);

        if(fabs(x1 - x0) <= 0.0001) break;
        x0 = x1;
    }

    printf("\nRoot found at %.6lf\n", x1);

    return 0;
}

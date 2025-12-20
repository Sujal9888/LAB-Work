#include <stdio.h>
#include <math.h>

double f(double x){
    return x*x*x + x*x - 3*x - 3;
}

int main(){
    double x1, x2, x3;
    int itr = 0;

    printf("\nEnter two initial guesses (x1 x2): ");
    scanf("%lf %lf", &x1, &x2);

    printf("\nSecant Method for f(x) = x^3 + x^2 - 3x - 3\n");
    printf("\n%-6s %-15s %-15s %-15s\n", "Iter", "X(n-1)", "X(n)", "X(n+1)");
    printf("---------------------------------------------------------------\n");

    do{
        itr++;
        x3 = x2 - (f(x2) * (x2 - x1)) / (f(x2) - f(x1));
        printf("%-6d %-15.6lf %-15.6lf %-15.6lf\n", itr, x1, x2, x3);

        x1 = x2;
        x2 = x3;

    } while(fabs(x2 - x1) >= 0.0001);

    printf("\nRoot ˜ %.6lf\n", x2);

    return 0;
}


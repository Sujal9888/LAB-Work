#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double x, result = 0.0;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    double coeff[n+1];

    printf("Enter the coefficients from highest degree to constant term:\n");
    for(i = 0; i <= n; i++){
        printf("a%d: ", n-i);
        scanf("%lf", &coeff[i]);
    }

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Horner's method
    result = coeff[0];
    for(i = 1; i <= n; i++){
        result = result * x + coeff[i];
    }

    printf("\nThe value of the polynomial at x = %.5lf is: %.5lf\n", x, result);

    return 0;
}


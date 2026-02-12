#include <stdio.h>

#define SIZE 10  // Maximum size of the system

int main() {
    int n, i, j, k;
    double a[SIZE][SIZE], x[SIZE], ratio;
    
	printf("--Gauss Elimination Method---\n");
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    // Gauss Elimination
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = i; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n-1] = a[n-1][n] / a[n-1][n-1];
    for (i = n-2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i+1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.4lf\n", i+1, x[i]);
    }

    return 0;
}


#include <stdio.h>
#include <math.h>

#define MAX 10  // Maximum number of variables

int main() {
    int n, i, j, k;
    float A[MAX][MAX], B[MAX], X[MAX], X_old[MAX], error[MAX];
    int max_iter;
    float tol;

    // Step 1: Input
    printf("---Gauss Seidel---\n");
    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter coefficients of matrix A (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter constants vector B:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &B[i]);

    printf("Enter initial guesses:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &X[i]);

    printf("Enter tolerance (e.g., 0.001): ");
    scanf("%f", &tol);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    printf("\nIteration Table:\n");
    printf("Iter\t");
    for (i = 0; i < n; i++) printf("x%d\t\t", i+1);
    for (i = 0; i < n; i++) printf("e%d\t\t", i+1);
    printf("\n");

    // Step 2: Iteration
    for (k = 0; k < max_iter; k++) {
        // Store previous values
        for (i = 0; i < n; i++)
            X_old[i] = X[i];

        // Gauss-Seidel formula
        for (i = 0; i < n; i++) {
            float sum = B[i];
            for (j = 0; j < n; j++) {
                if (j != i)
                    sum -= A[i][j] * X[j];
            }
            X[i] = sum / A[i][i];
        }

        // Calculate errors
        int converged = 1;
        for (i = 0; i < n; i++) {
            if (X[i] != 0)
                error[i] = fabs((X[i] - X_old[i]) / X[i]) * 100;
            else
                error[i] = fabs(X[i] - X_old[i]);
            
            if (error[i] > tol)
                converged = 0;
        }

        // Print iteration
        printf("%d\t", k+1);
        for (i = 0; i < n; i++)
            printf("%.6f\t", X[i]);
        for (i = 0; i < n; i++)
            printf("%.6f\t", error[i]);
        printf("\n");

        // Check convergence
        if (converged) {
            printf("\nConvergence achieved in %d iterations.\n", k+1);
            break;
        }  
    }

    // Step 3: Print solution
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.6f\n", i+1, X[i]);

    return 0;
}


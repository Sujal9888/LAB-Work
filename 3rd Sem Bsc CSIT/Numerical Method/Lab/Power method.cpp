#include <stdio.h>
#include <math.h>

int main(){
    int n,i,j,k;
    float A[10][10], x[10], y[10];
    float lambda, lambda_old = 0, error;

    printf("--- Power Method (To find Eigen values) ---\n");

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f",&A[i][j]);

    // Initial vector
    for(i=0;i<n;i++)
        x[i]=1;

    for(k=0;k<20;k++){

        // y = A*x
        for(i=0;i<n;i++){
            y[i]=0;
            for(j=0;j<n;j++)
                y[i] += A[i][j]*x[j];
        }

        // find max element
        lambda = fabs(y[0]);
        for(i=1;i<n;i++)
            if(fabs(y[i]) > lambda)
                lambda = fabs(y[i]);

        // normalize
        for(i=0;i<n;i++)
            x[i] = y[i]/lambda;

        // compute error
        error = fabs(lambda - lambda_old);
        lambda_old = lambda;
    }

    printf("\nLargest Eigenvalue = %.6f\n", lambda);

    printf("Final Eigenvector X:\n");
    for(i=0;i<n;i++)
        printf("x%d = %.6f\n", i+1, x[i]);

    printf("Final Error = %.6f\n", error);

    return 0;
}


#include <stdio.h>
#include <math.h>

int main(){
    int n,i,j,iter=0,max_iter;
    float a[10][10], b[10], x[10]={0}, xnew[10], err[10], tol;

    printf("---Jacobi Method---\n");
    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter coefficient matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f",&a[i][j]);

    printf("Enter constants:\n");
    for(i=0;i<n;i++)
        scanf("%f",&b[i]);

    printf("Enter tolerance: ");
    scanf("%f",&tol);

    printf("Enter max iterations: ");
    scanf("%d",&max_iter);

    // check diagonal
    for(i=0;i<n;i++){
        if(fabs(a[i][i]) < 1e-8){
            printf("Zero diagonal element — cannot use Jacobi\n");
            return 0;
        }
    }

    // table header
    printf("\nIter\t");
    for(i=0;i<n;i++) printf("x%d\t\t", i+1);
    for(i=0;i<n;i++) printf("e%d\t\t", i+1);
    printf("\n");

    // iterations
    do{
        // compute new values
        for(i=0;i<n;i++){
            float sum = b[i];
            for(j=0;j<n;j++)
                if(j!=i)
                    sum -= a[i][j]*x[j];

            xnew[i] = sum / a[i][i];
        }

        // compute errors
        float max_err = 0;
        for(i=0;i<n;i++){
            err[i] = fabs(xnew[i] - x[i]);
            if(err[i] > max_err) max_err = err[i];
        }

        // print row
        printf("%d\t", iter+1);
        for(i=0;i<n;i++) printf("%.6f\t", xnew[i]);
        for(i=0;i<n;i++) printf("%.6f\t", err[i]);
        printf("\n");

        // copy new ? old
        for(i=0;i<n;i++)
            x[i] = xnew[i];

        iter++;

        if(max_err < tol) break;

    } while(iter < max_iter);

    printf("\nSolution:\n");
    for(i=0;i<n;i++)
        printf("x%d = %.6f\n", i+1, x[i]);

    printf("Iterations used = %d\n", iter);

    return 0;
}


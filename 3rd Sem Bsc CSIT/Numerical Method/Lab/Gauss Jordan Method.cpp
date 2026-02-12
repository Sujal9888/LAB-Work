#include <stdio.h>
#include <math.h>

int main(){
    int n,i,j,k;
    float a[20][21], ratio, temp;

    printf("---Gauss Jordan Method---\n");
    printf("Enter number of variables: ");
    scanf("%d",&n);

    printf("Enter augmented matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<=n;j++)
            scanf("%f",&a[i][j]);

    for(i=0;i<n;i++){

        // Pivot check and row swap
        if(fabs(a[i][i]) < 1e-6){
            for(j=i+1;j<n;j++){
                if(fabs(a[j][i]) > 1e-6){
                    for(k=0;k<=n;k++){
                        temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }
                    break;
                }
            }
        }

        // Normalize pivot row
        temp = a[i][i];
        for(k=0;k<=n;k++)
            a[i][k] /= temp;

        // Eliminate other rows
        for(j=0;j<n;j++){
            if(i!=j){
                ratio = a[j][i];
                for(k=0;k<=n;k++)
                    a[j][k] -= ratio * a[i][k];
            }
        }
    }

    printf("\nSolution:\n");
    for(i=0;i<n;i++)
        printf("x%d = %.4f\n", i+1, a[i][n]);

    return 0;
}


#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return x*y;
}

int main()
{
    float a,b,c,d,hx,hy,sum=0;
    int nx,ny,i,j;
	printf("---Double Integration Trapezoidal Rule---\n ");
    printf("Enter x-lower and x-upper: ");
    scanf("%f %f",&a,&b);
    printf("Enter y-lower and y-upper: ");
    scanf("%f %f",&c,&d);
    printf("Enter nx and ny: ");
    scanf("%d %d",&nx,&ny);

    hx=(b-a)/nx;
    hy=(d-c)/ny;

    for(i=0;i<=nx;i++)
    {
        for(j=0;j<=ny;j++)
        {
            float x=a+i*hx;
            float y=c+j*hy;
            sum+=f(x,y);
        }
    }

    printf("Double Integration = %f",sum*hx*hy);

    return 0;
}


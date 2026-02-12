#include <stdio.h>

// Function f(x,y) = dy/dx
float f(float x, float y) {
    return x + y;
}

// Euler's Method
float euler(float x0, float y0, float x, float h) {
    int n = (int)((x - x0)/h);
    float y = y0;
    for(int i = 0; i < n; i++) {
        y = y + h * f(x0, y);
        x0 = x0 + h;
    }
    return y;
}

// Heun's Method (Improved Euler)
float heun(float x0, float y0, float x, float h) {
    int n = (int)((x - x0)/h);
    float y = y0;
    for(int i = 0; i < n; i++) {
        float k1 = f(x0, y);
        float k2 = f(x0 + h, y + h * k1);
        y = y + (h/2.0) * (k1 + k2);
        x0 = x0 + h;
    }
    return y;
}

// RK4 Method
float rk4(float x0, float y0, float x, float h) {
    int n = (int)((x - x0)/h);
    float y = y0;
    for(int i = 0; i < n; i++) {
        float k1 = f(x0, y);
        float k2 = f(x0 + h/2.0, y + h*k1/2.0);
        float k3 = f(x0 + h/2.0, y + h*k2/2.0);
        float k4 = f(x0 + h, y + h*k3);
        y = y + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4);
        x0 = x0 + h;
    }
    return y;
}

int main() {
    float x0, y0, x, h1, h2;
	printf("---Ordinary Differential Equations---\n");
    // Taking input from user
    printf("Enter initial x0: ");
    scanf("%f", &x0);
    printf("Enter initial y0: ");
    scanf("%f", &y0);
    printf("Enter value of x to find y(x): ");
    scanf("%f", &x);
    printf("Enter step size h1: ");
    scanf("%f", &h1);
    printf("Enter step size h2: ");
    scanf("%f", &h2);

    printf("\n--- Step size h = %.3f ---\n", h1);
    printf("Euler: y(%.3f) = %.6f\n", x, euler(x0, y0, x, h1));
    printf("Heun:  y(%.3f) = %.6f\n", x, heun(x0, y0, x, h1));
    printf("RK4:   y(%.3f) = %.6f\n", x, rk4(x0, y0, x, h1));

    printf("\n--- Step size h = %.3f ---\n", h2);
    printf("Euler: y(%.3f) = %.6f\n", x, euler(x0, y0, x, h2));
    printf("Heun:  y(%.3f) = %.6f\n", x, heun(x0, y0, x, h2));
    printf("RK4:   y(%.3f) = %.6f\n", x, rk4(x0, y0, x, h2));

    return 0;
}


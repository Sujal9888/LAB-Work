#include <iostream>
using namespace std;

// Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    int a = 56, b = 98;
    cout << "GCD: " << gcd(a, b) << endl;
    
    int x, y;
    int g = extendedGCD(a, b, x, y);
    cout << "Extended GCD: gcd(" << a << ", " << b << ") = " << g << ", x = " << x << ", y = " << y << endl;
    return 0;
}


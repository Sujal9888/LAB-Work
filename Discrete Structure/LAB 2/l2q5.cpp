#include <iostream>
using namespace std;

int modInverse(int a, int m) {
    int m0 = m, x0 = 0, x1 = 1;
    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m; a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    return (x1 + m0) % m0;
}

int solveLinearCongruence(int a, int b, int m) {
    int inv = modInverse(a, m);
    return (inv * b) % m;
}

int main() {
    int a = 3, b = 2, m = 7;
    cout << "Solution to " << a << "x = " << b << " (mod " << m << ") is x = "
         << solveLinearCongruence(a, b, m) << endl;
    return 0;
}


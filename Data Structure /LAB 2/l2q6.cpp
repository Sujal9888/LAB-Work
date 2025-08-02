#include <iostream>
using namespace std;

// Function to calculate modular inverse using extended Euclidean algorithm
int modInverse(int a, int m) {
    int m0 = m, x0 = 0, x1 = 1;
    // Iterate while 'a' is greater than 1
    while (a > 1) {
        // Calculate quotient and remainder
        int q = a / m;
        int t = m;

        // Update m and a for the next iteration
        m = a % m;
        a = t;

        // Update x0 and x1
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    // Ensure x1 is positive
    return (x1 + m0) % m0;
}

// Function to solve Chinese Remainder Theorem
int chineseRemainder(int num[], int rem[], int k) {
    // Calculate product of all numbers (moduli)
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    // Initialize result
    int result = 0;
    // Iterate through each congruence
    for (int i = 0; i < k; i++) {
        // Calculate partial product (prod / num[i])
        int pp = prod / num[i];
        // Add to result: rem[i] * modInverse(pp, num[i]) * pp
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    // Return the result modulo prod
    return result % prod;
}

int main() {
    // Define arrays for numbers (moduli) and remainders
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    // Calculate the number of congruences
    int k = sizeof(num) / sizeof(num[0]);

    // Display the congruences (moduli and remainders)
    cout << "Solving system of congruences:" << endl;
    for (int i = 0; i < k; ++i) {
        cout << "x % " << num[i] << " = " << rem[i] << endl;
    }

    // Calculate and display the result
    cout << "x = " << chineseRemainder(num, rem, k) << endl;

    return 0;
}

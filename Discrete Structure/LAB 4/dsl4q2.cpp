#include <iostream>
using namespace std;

int modPower(int b, int n, int m) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result = (result * b) % m;
    }
    return result;
}

int main() {
    int b, n, m;
    cout << "Enter base (b): ";
    cin >> b;
    cout << "Enter exponent (n): ";
    cin >> n;
    cout << "Enter modulus (m): ";
    cin >> m;
    cout << "Result: " << modPower(b, n, m) << endl;
    return 0;
}

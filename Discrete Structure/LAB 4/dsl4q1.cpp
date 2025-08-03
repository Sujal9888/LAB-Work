#include <iostream>
using namespace std;

int power(int a, int n) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= a;
    }
    return result;
}

int main() {
    int a, n;
    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter exponent (n): ";
    cin >> n;
    cout << "Result: " << power(a, n) << endl;
    return 0;
}

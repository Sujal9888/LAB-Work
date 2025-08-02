#include <iostream>
using namespace std;

void primeFactors(int n) {
    cout << "Prime factors of " << n << " are: ";
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n;
    cout << endl;
}

int main() {
    int n = 84;
    primeFactors(n);
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n, i;
    unsigned long long factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Factorial using for loop: ";
    factorial = 1;
    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }
    cout << factorial << endl;
	cout << "Factorial using while loop: ";
    factorial = 1;
    i = 1;
    while (i <= n) {
        factorial *= i;
        ++i;
    }
   cout << factorial << endl;

    return 0;
}


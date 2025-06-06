#include <iostream>

using namespace std;

int main() {
    int n;
    long long factorial = 1;

    cout << "Enter a non-negative integer for factorial (For Loop): ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } 
	else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
		 cout << "Factorial of " << n << " = " << factorial << endl;
    }

    return 0;
}

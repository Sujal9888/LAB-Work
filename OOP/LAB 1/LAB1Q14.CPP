#include <iostream>

using namespace std;

int main() {
    double num1, num2, num3;

    cout << "Enter three numbers: " << endl;
    cout << "Number 1: ";
    cin >> num1;
    cout << "Number 2: ";
    cin >> num2;
    cout << "Number 3: ";
    cin >> num3;

    if (num1 >= num2 && num1 >= num3) {
        cout << "The largest number is: " << num1 << endl;
    } else if (num2 >= num1 && num2 >= num3) {
        cout << "The largest number is: " << num2 << endl;
    } else {
        cout << "The largest number is: " << num3 << endl;
    }

    return 0;
}

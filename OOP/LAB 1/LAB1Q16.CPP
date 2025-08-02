#include <iostream>

using namespace std;

void swapFloats(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int main() {
    float num1, num2;

    cout << "Enter first float number: ";
    cin >> num1;

    cout << "Enter second float number: ";
    cin >> num2;

    cout << "Before swapping:" << endl;
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;

    swapFloats(num1, num2);

    cout << "\nAfter swapping:" << endl;
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Template swap function
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// OOP class to demonstrate swapping
class Swapper {
public:
    // Member function to call the template swap
    template <typename T>
    void performSwap(T& x, T& y) {
        cout << "Before swap: x = " << x << ", y = " << y << endl;
        swapValues(x, y);
        cout << "After swap:  x = " << x << ", y = " << y << endl << endl;
    }
};

int main() {
    Swapper s;

    // Test with int
    int a = 10, b = 20;
    s.performSwap(a, b);

    // Test with float
    float f1 = 1.5, f2 = 2.5;
    s.performSwap(f1, f2);

    // Test with char
    char c1 = 'A', c2 = 'B';
    s.performSwap(c1, c2);

    // Test with double
    double d1 = 3.1415, d2 = 2.7182;
    s.performSwap(d1, d2);

    return 0;
}

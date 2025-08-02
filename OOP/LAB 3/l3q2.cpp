#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v = 0) : value(v) {}

    // Declare friend function
    friend Number operator-(Number);

    void display() {
        cout << "Value: " << value << endl;
    }
};

// Define the friend function
Number operator-(Number n) {
    n.value = -n.value;
    return n;
}

int main() {
    Number num(10);
    Number negNum;

    cout << "Original ";
    num.display();

    negNum = -num;

    cout << "After applying unary minus ";
    negNum.display();

    return 0;
}

#include <iostream>
using namespace std;

// Class template for Calculator
template <typename T>
class Calculator {
private:
    T num1, num2;

public:
    // Constructor
    Calculator(T a, T b) : num1(a), num2(b) {}

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }

    T multiply() {
        return num1 * num2;
    }

    void divide() {
        if (num2 == 0) {
            cout << "Division: Error! Division by zero." << endl;
        } else {
            cout << "Division: " << num1 / num2 << endl;
        }
    }

    void displayResults() {
        cout << "Addition: " << add() << endl;
        cout << "Subtraction: " << subtract() << endl;
        cout << "Multiplication: " << multiply() << endl;
        divide();
        cout << "------------------------" << endl;
    }
};

int main() {
    // Integer calculator
    Calculator<int> intCalc(10, 5);
    cout << "Integer Calculator:" << endl;
    intCalc.displayResults();

    // Float calculator
    Calculator<float> floatCalc(5.5f, 2.2f);
    cout << "Float Calculator:" << endl;
    floatCalc.displayResults();

    // Double calculator
    Calculator<double> doubleCalc(9.8, 3.3);
    cout << "Double Calculator:" << endl;
    doubleCalc.displayResults();

    // Char calculator (ASCII arithmetic)
    Calculator<char> charCalc('A', 'B'); // 'A' = 65, 'B' = 66
    cout << "Char Calculator (ASCII values):" << endl;
    charCalc.displayResults();

    return 0;
}

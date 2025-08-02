#include <iostream>
#include <string>

using namespace std;

// Overload 1: Parameters with a different type
void display(int num) {
    cout << "Displaying integer: " << num << endl;
}

void display(double num) {
    cout << "Displaying double: " << num << endl;
}

void display(string text) {
    cout << "Displaying string: " << text << endl;
}

// Overload 2: Different number of parameters
void calculateSum(int a, int b) {
    cout << "Sum of two integers: " << (a + b) << endl;
}

void calculateSum(int a, int b, int c) {
    cout << "Sum of three integers: " << (a + b + c) << endl;
}

// Overload 3: Parameters with a different sequence of parameters
void printDetails(int id, string name) {
    cout << "ID: " << id << ", Name: " << name << endl;
}

void printDetails(string name, int id) {
    cout << "Name: " << name << ", ID: " << id << endl;
}

int main() {
    cout << "--- Function Overloading: Different Parameter Types ---" << endl;
    display(10);          // Calls display(int)
    display(20.5);        // Calls display(double)
    display("Hello!");    // Calls display(string)

    cout << "\n--- Function Overloading: Different Number of Parameters ---" << endl;
    calculateSum(5, 10);      // Calls calculateSum(int, int)
    calculateSum(1, 2, 3);    // Calls calculateSum(int, int, int)

    cout << "\n--- Function Overloading: Different Sequence of Parameters ---" << endl;
    printDetails(101, "Alice"); // Calls printDetails(int, string)
    printDetails("Bob", 102);   // Calls printDetails(string, int)

    return 0;
}

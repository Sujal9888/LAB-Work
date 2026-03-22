#include <iostream>
#include <bitset>
using namespace std;

// Function to display 4-bit binary
void displayBinary(int num) {
    cout << bitset<4>(num);
}

// 1's complement subtraction
int subtract_ones(int A, int B) {
    int B_ones = (~B) & 0xF;      // 4-bit 1's complement
    int sum = A + B_ones;

    int carry = (sum >> 4) & 1;   // end-around carry
    sum = (sum & 0xF) + carry;

    return sum & 0xF;
}

// 2's complement subtraction
int subtract_twos(int A, int B) {
    int B_twos = ((~B) + 1) & 0xF;   // 4-bit 2's complement
    int sum = (A + B_twos) & 0xF;

    return sum;
}

int main() {
    int A, B;

    cout << "Enter two 4-bit numbers A and B (0-15): ";
    cin >> A >> B;

    // Range check
    if (A < 0 || A > 15 || B < 0 || B > 15) {
        cout << "Error: Enter numbers between 0 and 15 only." << endl;
        return 0;
    }

    int result1 = subtract_ones(A, B);
    int result2 = subtract_twos(A, B);

    cout << "\nA in binary: ";
    displayBinary(A);

    cout << "\nB in binary: ";
    displayBinary(B);

    cout << "\n\n1's Complement Result (A-B): "
         << result1 << " (";
    displayBinary(result1);
    cout << ")";	

    cout << "\n2's Complement Result (A-B): "
         << result2 << " (";
    displayBinary(result2);
    cout << ")";

    return 0;
}

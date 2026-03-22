#include <iostream>
using namespace std;

// Restoring division
void restoring_division(int dividend, int divisor) {
    int R = 0, Q = dividend;
    int n = 4; // number of bits

    cout << "\nRestoring Division Steps:\n";

    for(int i = 0; i < n; i++) {
        // Shift left R and bring MSB of Q
        R = (R << 1) | ((Q >> 3) & 1);

        // Shift left Q
        Q = (Q << 1) & 0xF;

        // Subtract divisor
        R = R - divisor;

        if(R >= 0)
            Q |= 1;      // set LSB of Q to 1
        else
            R = R + divisor; // restore

        cout << "Step " << i+1
             << ": R=" << R
             << " Q=" << Q << endl;
    }

    cout << "Final Quotient = " << Q
         << "  Remainder = " << R << endl;
}

// Non-Restoring division
void non_restoring_division(int dividend, int divisor) {
    int R = 0, Q = dividend;
    int n = 4;

    cout << "\nNon-Restoring Division Steps:\n";

    for(int i = 0; i < n; i++) {
        // Shift left
        R = (R << 1) | ((Q >> 3) & 1);
        Q = (Q << 1) & 0xF;

        if(R >= 0)
            R = R - divisor;
        else
            R = R + divisor;

        if(R >= 0)
            Q |= 1;

        cout << "Step " << i+1
             << ": R=" << R
             << " Q=" << Q << endl;
    }

    // Final correction step
    if(R < 0)
        R = R + divisor;

    cout << "Final Quotient = " << Q
         << "  Remainder = " << R << endl;
}

int main() {
    int dividend, divisor;

    cout << "Enter dividend and divisor (0-15): ";
    cin >> dividend >> divisor;

    if(divisor == 0) {
        cout << "Error: Division by zero not allowed." << endl;
        return 0;
    }

    restoring_division(dividend, divisor);
    non_restoring_division(dividend, divisor);

    return 0;
}

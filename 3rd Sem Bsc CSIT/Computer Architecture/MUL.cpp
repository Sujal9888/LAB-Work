#include <iostream>
using namespace std;

// Shift & Add multiplication
int shift_add_multiply(int A, int B) {
    int result = 0;

    for(int i = 0; i < 4; i++) {
        if((B >> i) & 1)
            result += (A << i);
    }

    return result;
}

// Booth's Algorithm
int booths_algorithm(int M, int Q) {
    int AC = 0;
    int Q_1 = 0;
    int n = 4;

    for(int i = 0; i < n; i++) {

        int Q0 = Q & 1;

        if(Q0 == 1 && Q_1 == 0)
            AC = AC - M;

        else if(Q0 == 0 && Q_1 == 1)
            AC = AC + M;

        // Arithmetic Right Shift
        Q_1 = Q & 1;

        Q = (Q >> 1) | ((AC & 1) << 3);
        AC = AC >> 1;
    }

    return (AC << 4) | (Q & 0xF);
}

int main() {
    int A, B;

    cout << "Enter two 4-bit numbers: ";
    cin >> A >> B;

    cout << "Shift & Add multiplication: "
         << shift_add_multiply(A, B) << endl;

    cout << "Booth's Algorithm multiplication: "
         << booths_algorithm(A, B) << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Function to check Reflexive property
bool isReflexive(int R[10][10], int n) {
    for (int i = 0; i < n; i++) {
        if (R[i][i] == 0)  // diagonal elements must be 1
            return false;
    }
    return true;
}

// Function to check Symmetric property
bool isSymmetric(int R[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (R[i][j] != R[j][i])
                return false;
        }
    }
    return true;
}

// Function to check Antisymmetric property
bool isAntisymmetric(int R[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && R[i][j] == 1 && R[j][i] == 1)
                return false;
        }
    }
    return true;
}

// Function to check Transitive property
bool isTransitive(int R[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (R[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (R[j][k] == 1 && R[i][k] == 0)
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    int R[10][10];

    cout << "Enter number of elements in the set: ";
    cin >> n;

    cout << "Enter the relation matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> R[i][j];
        }
    }

    cout << "\nProperties of the relation:\n";
    cout << "Reflexive: " << (isReflexive(R, n) ? "Yes" : "No") << endl;
    cout << "Symmetric: " << (isSymmetric(R, n) ? "Yes" : "No") << endl;
    cout << "Antisymmetric: " << (isAntisymmetric(R, n) ? "Yes" : "No") << endl;
    cout << "Transitive: " << (isTransitive(R, n) ? "Yes" : "No") << endl;

    return 0;
}


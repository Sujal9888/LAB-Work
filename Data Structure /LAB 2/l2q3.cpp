   #include <iostream>
using namespace std;

const int SIZE = 3;

void printMatrix(bool mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void join(bool A[SIZE][SIZE], bool B[SIZE][SIZE], bool result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = A[i][j] | B[i][j];
}

void meet(bool A[SIZE][SIZE], bool B[SIZE][SIZE], bool result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = A[i][j] & B[i][j];
}

void booleanProduct(bool A[SIZE][SIZE], bool B[SIZE][SIZE], bool result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
                result[i][j] |= A[i][k] & B[k][j];
        }
}

int main() {
    bool A[SIZE][SIZE] = {{1, 0, 1}, {0, 1, 1}, {1, 1, 0}};
    bool B[SIZE][SIZE] = {{0, 1, 0}, {1, 0, 1}, {1, 1, 1}};
    bool result[SIZE][SIZE];

    cout << "Join (OR):\n";
    join(A, B, result);
    printMatrix(result);

    cout << "Meet (AND):\n";
    meet(A, B, result);
    printMatrix(result);

    cout << "Boolean Product:\n";
    booleanProduct(A, B, result);
    printMatrix(result);

    return 0;
}

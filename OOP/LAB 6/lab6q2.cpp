#include <iostream>
using namespace std;

// Template function to sum elements of an array
template <typename T>
T sumArray(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Integer array
    int intArr[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Sum of integer array: " << sumArray(intArr, intSize) << endl;

    // Float array
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "Sum of float array: " << sumArray(floatArr, floatSize) << endl;

    // Double array
    double doubleArr[] = {0.5, 1.5, 2.5};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "Sum of double array: " << sumArray(doubleArr, doubleSize) << endl;

    return 0;
}

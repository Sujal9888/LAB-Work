#include <iostream>
using namespace std;

// Template function to find minimum value in an array
template <typename T>
T findMin(T arr[], int size) {
    T minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    // Integer array
    int intArr[] = {5, 2, 8, 1, 9};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Minimum in integer array: " << findMin(intArr, intSize) << endl;

    // Float array
    float floatArr[] = {3.5f, 2.1f, 4.8f, 1.9f};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "Minimum in float array: " << findMin(floatArr, floatSize) << endl;

    // Double array
    double doubleArr[] = {2.2, 3.3, 1.1, 4.4};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "Minimum in double array: " << findMin(doubleArr, doubleSize) << endl;

    // Char array
    char charArr[] = {'z', 'a', 'm', 'b'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    cout << "Minimum in char array: " << findMin(charArr, charSize) << endl;

    return 0;
}

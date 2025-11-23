#include <iostream>
using namespace std;

int main() {
    int n, j, i;

    cout << "Enter no. of array elements: ";
    cin >> n;

    int a[n];  // declare array AFTER reading n

    cout << "Enter array: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter position of element to delete: ";
    cin >> j;

    cout << "Before deletion:" << endl;
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // Delete element by shifting
    for (i = j - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;  // reduce size

    cout << "\nAfter deletion:" << endl;
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}


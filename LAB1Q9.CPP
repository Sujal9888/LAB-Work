#include <iostream>

using namespace std;

int main() {
    int count;

    cout << "Enter how many times to display the message: ";
    cin >> count;

    if (count < 0) {
        cout << "Please enter a non-negative number." << endl;
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        cout << "Welcome to ACHS College" << endl;
    }

    return 0;
}

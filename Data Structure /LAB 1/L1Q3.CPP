#include <iostream>
#include <cmath>  // For ceil() and floor()

using namespace std;

int main() {
    double num;
    cout << "Enter a real number: ";
    cin >> num;

    int ceilVal = (int)ceil(num);
    int floorVal = (int)floor(num);

    cout << "Ceiling: " << ceilVal << endl;
    cout << "Floor: " << floorVal << endl;

    return 0;
}

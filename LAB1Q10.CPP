#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double f_temp;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> f_temp;

    double *c_temp_ptr = new double;

    *c_temp_ptr = (f_temp - 32) / 1.8;

    cout << fixed << setprecision(2);
    cout << "Temperature in Celsius: " << *c_temp_ptr << " C" << endl;

    delete c_temp_ptr;
    

    return 0;
}

#include <iostream>
#include "myheader.h" 
using namespace std;

int main() {
    greet(); // Call the function from myheader.h
    int sum = add(10, 20); // Call another function from myheader.h
    cout << "The sum is: " << sum << endl;
    return 0;
}

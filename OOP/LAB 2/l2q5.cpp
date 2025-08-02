#include <iostream>
using namespace std;

class Distance {
private:
    int feet, inches;

public:
    void getData() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void addDistance(Distance d1, Distance d2) {
        inches = d1.inches + d2.inches;
        feet = d1.feet + d2.feet + inches / 12;
        inches = inches % 12;
    }

    void display() {
        cout << "Total Distance = " << feet << " feet and " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1, d2, d3;
    cout << "Enter first distance:\n";
    d1.getData();
    cout << "Enter second distance:\n";
    d2.getData();
    d3.addDistance(d1, d2);
    d3.display();
    return 0;
}

#include <iostream>

using namespace std;

class Feet {
public:
    double ft;
    double inch;

    Feet(double f = 0, double i = 0) : ft(f), inch(i) {}

    double toTotalFeet() const {
        return ft + inch / 12.0;
    }
};

class Kilometer {
public:
    int km;
    double m;

    Kilometer(int k = 0, double mo = 0) : km(k), m(mo) {}

    Kilometer(const Feet& f) {
        double totalFeet = f.toTotalFeet();
        const double FEET_PER_KM = 328.0; 

        double totalKmDouble = totalFeet / FEET_PER_KM;

        km = static_cast<int>(totalKmDouble);
        m = (totalKmDouble - km) * 1000.0;
    }

    void display(){
        cout << km << " km " << m << " m" << endl;
    }
};

int main() {
    Feet distanceInFeet(5000, 6); // 5000 feet, 6 inches

    Kilometer distanceInKm = distanceInFeet; // Convert Feet object to Kilometer object

    cout << "Original distance: " << distanceInFeet.ft << " ft " << distanceInFeet.inch << " inches" << endl;
    cout << "Converted distance: ";
    distanceInKm.display();

    Feet anotherDistance(10000, 0); // 10000 feet, 0 inches
    Kilometer anotherKm = anotherDistance;
    cout << "\nOriginal distance: " << anotherDistance.ft << " ft " << anotherDistance.inch << " inches" << endl;
    cout << "Converted distance: ";
    anotherKm.display();

    Feet smallDistance(1, 0); // 1 foot
    Kilometer smallKm = smallDistance;
    cout << "\nOriginal distance: " << smallDistance.ft << " ft " << smallDistance.inch << " inches" << endl;
    cout << "Converted distance: ";
    smallKm.display();

    return 0;
}


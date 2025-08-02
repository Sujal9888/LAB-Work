#include <iostream>
using namespace std;

class Velocity;

class Distance {
    float d;
public:
    void getDistance() {
        cout << "Enter distance (in meters): ";
        cin >> d;
    }
    friend class Velocity;
};

class Time {
    float t;
public:
    void getTime() {
        cout << "Enter time (in seconds): ";
        cin >> t;
    }
    friend class Velocity;
};

class Velocity {
public:
    void calculate(Distance d, Time t) {
        float v = d.d / t.t;
        cout << "Velocity = " << v << " m/s" << endl;
    }
};

int main() {
    Distance d;
    Time t;
    Velocity v;
    d.getDistance();
    t.getTime();
    v.calculate(d, t);
    return 0;
}


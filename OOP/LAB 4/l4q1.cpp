#include <iostream>
using namespace std;

class Polygon {
protected:
    float width, height;
public:
    void getData() {
        cout << "Enter width and height: "<<endl;
        cin >> width >> height;
    }
};

class Rectangle : public Polygon {
public:
    void calculate_area() {
        cout << "Rectangle Area: " << width * height << endl;
    }
    void calculate_perimeter() {
        cout << "Rectangle Perimeter: " << 2 * (width + height) << endl;
    }
};

class Triangle : public Polygon {
public:
    void calculate_area() {
        cout << "Triangle Area: " << 0.5 * width * height << endl;
    }
    void calculate_perimeter() {
        cout << "Enter third side: ";
        float side;
        cin >> side;
        cout << "Triangle Perimeter: " << width + height + side << endl;
    }
};

int main() {
    Rectangle r;
    Triangle t;

    cout << "\nRectangle:\n";
    r.getData();
    r.calculate_area();
    r.calculate_perimeter();

    cout << "\nTriangle:\n";
    t.getData();
    t.calculate_area();
    t.calculate_perimeter();

    return 0;
}

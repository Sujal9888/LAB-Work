#include <iostream> 

#define PI 3.14159 
using namespace std; 

int main() {

    double radius; 

  
    cout << "Enter the radius of the circle: ";
    cin >> radius; 

   
    double area = PI * radius * radius;
    cout << "Area of the circle: " << area << endl;


    double circumference = 2 * PI * radius;
    cout << "Circumference of the circle: " << circumference << endl;

    return 0; 
}

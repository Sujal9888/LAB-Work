#include <iostream> 

 using namespace std; 
 
int main() {

    int intVar = 10;       
    float floatVar = 5.5f; 

  
    float result = intVar + floatVar;

    cout << "Integer variable: " << intVar << endl;
    cout << "Float variable: " << floatVar << endl;
    cout << "Result of int + float (stored in float): " << result << endl;
    cout << "Type of result: float (due to automatic type conversion)" << endl;

    return 0; 
}

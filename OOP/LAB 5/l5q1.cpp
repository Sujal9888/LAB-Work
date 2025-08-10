#include <iostream>
#include <string>
using namespace std;

class Fmachine {
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    virtual ~Fmachine() {}
};

class Aeroplane : public Fmachine {
private:
    string code;
    string name;
    int capacity;

public:
    Aeroplane() : code(""), name(""), capacity(0) {}

    void getdata() {
        cout << "Enter aeroplane code: ";
        cin >> code;
        cout << "Enter aeroplane name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter capacity: ";
        cin >> capacity;
    }

    void putdata() {
        cout << "\n--- Aeroplane Details ---\n";
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "-------------------------\n";
    }
};

int main() {
    Fmachine* ptr;

    ptr = new Aeroplane();

    ptr->getdata();
    ptr->putdata();

    delete ptr;


    return 0;
}


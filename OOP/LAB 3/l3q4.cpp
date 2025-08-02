 #include <iostream>
using namespace std;

class Student {
    string name;
    int age;
public:
    // Friend functions for operator overloading
    friend ostream& operator<<(ostream& out, const Student& s);
    friend istream& operator>>(istream& in, Student& s);
};

// Overload insertion operator
ostream& operator<<(ostream& out, const Student& s) {
    out << "Name: " << s.name << ", Age: " << s.age;
    return out;
}

// Overload extraction operator
istream& operator>>(istream& in, Student& s) {
    cout << "Enter name: ";
    in >> s.name;
    cout << "Enter age: ";
    in >> s.age;
    return in;
}

int main() {
    Student s1;
    cin >> s1;
    cout << "Student Details: " << s1 << endl;
    return 0;
}

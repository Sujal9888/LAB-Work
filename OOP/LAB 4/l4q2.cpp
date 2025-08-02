#include <iostream>
using namespace std;

class Lecturer {
protected:
    string name;
    int id;
public:
    string courseId, course_Name;
    virtual void display() {
        cout << "Lecturer Name: " << name << "\nID: " << id << endl;
    }
    void input() {
        cout << "Enter name and ID: "<<endl;
        cin >> name >> id;
        cout << "Enter Course ID and Name: "<<endl;
        cin >> courseId >> course_Name;
    }
};

class PartTimeFaculty : public Lecturer {
private:
    float payPerHour;
public:
    void input() {
        Lecturer::input();
        cout << "Enter Pay Per Hour: ";
        cin >> payPerHour;
    }
    void display()  {
        Lecturer::display();
        cout << "Pay Per Hour: " << payPerHour << endl;
    }
};

class FullTimeFaculty : public Lecturer {
private:
    float salary;
public:
    void input() {
        Lecturer::input();
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void display()  {
        Lecturer::display();
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    PartTimeFaculty pt;
    FullTimeFaculty ft;

    cout << "\nEnter Part-Time Faculty Info:\n";
    pt.input();
    pt.display();

    cout << "\nEnter Full-Time Faculty Info:\n";
    ft.input();
    ft.display();

    return 0;
}

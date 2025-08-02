#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int roll_no;
public:
    void inputStudent() {
        cout << "Enter student name and roll number: "<<endl;
        cin >> name >> roll_no;
    }
    void displayStudent() {
        cout << "Name: " << name << "\nRoll No: " << roll_no << endl;
    }
};

class Exam : public Student {
protected:
    int marks[5];
public:
    void inputMarks() {
        cout << "Enter marks of 5 subjects:\n";
        for(int i = 0; i < 5; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }
    void displayMarks() {
        for(int i = 0; i < 5; i++) {
            cout << "Subject " << i + 1 << " Marks: " << marks[i] << endl;
        }
    }
};

class Result : public Exam {
public:
    void displayResult() {
        int total = 0;
        for(int i = 0; i < 5; i++){
            total += marks[i];
        }

        float percentage = total / 5.0;
        displayStudent();
        displayMarks();
        cout << "Total Marks: " << total << "\nPercentage: " << percentage << "%" << endl;
    }
};

int main() {
    Result r;
    r.inputStudent();
    r.inputMarks();
    cout << "\n--- Student Result ---\n";
    r.displayResult();
    return 0;
}

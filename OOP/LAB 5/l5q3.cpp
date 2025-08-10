#include <iostream>
#include <string>
using namespace std;

// Class Student as a virtual base class
class Student {
protected:
    int roll_no;
    string name;

public:
    void readStudentData() {
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter name: ";
        cin.ignore(); // Clears the input buffer
        getline(cin, name);
    }

    void displayStudentData() {
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};

// Class Test inherits Student virtually
class Test : virtual public Student {
protected:
    float subject1_marks;
    float subject2_marks;

public:
    void readTestMarks() {
        cout << "Enter marks for subject 1: ";
        cin >> subject1_marks;
        cout << "Enter marks for subject 2: ";
        cin >> subject2_marks;
    }

    void displayTestMarks() {
        cout << "Subject 1 Marks: " << subject1_marks << endl;
        cout << "Subject 2 Marks: " << subject2_marks << endl;
    }
};

// Class Sports inherits Student virtually
class Sports : virtual public Student {
protected:
    float sports_score;

public:
    void readSportsScore() {
        cout << "Enter sports score: ";
        cin >> sports_score;
    }

    void displaySportsScore() {
        cout << "Sports Score: " << sports_score << endl;
    }
};

// Class Result inherits from Test and Sports
class Result : public Test, public Sports {
private:
    float total_marks;

public:
    void calculateTotalMarks() {
        total_marks = subject1_marks + subject2_marks + sports_score;
    }

    void displayAllData() {
        cout << "\n--- Student Result ---\n";
        displayStudentData();
        displayTestMarks();
        displaySportsScore();
        cout << "Total Marks: " << total_marks << endl;
        cout << "----------------------\n";
    }
};

int main() {
    Result student1;

    // Read all the data
    student1.readStudentData();
    student1.readTestMarks();
    student1.readSportsScore();

    // Calculate and display the results
    student1.calculateTotalMarks();
    student1.displayAllData();

    return 0;
}


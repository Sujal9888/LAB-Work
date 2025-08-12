#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    char stdname[50];
    int mark;
};

int main() {
    Student s1;

    // Input student data
    cout << "Enter student name: ";
    cin.getline(s1.stdname, 50);

    cout << "Enter marks: ";
    cin >> s1.mark;

    // Write to file
    ofstream fout("studentfile.txt", ios::binary);
    fout.write((char*)&s1, sizeof(s1));
    fout.close();

    // Read from file
    Student s2;
    ifstream fin("studentfile.txt", ios::binary);
    fin.read((char*)&s2, sizeof(s2));
    fin.close();

    // Display read data
    cout << "\nRead from file:\n";
    cout << "Name: " << s2.stdname << "\nMarks: " << s2.mark << endl;

    return 0;
}

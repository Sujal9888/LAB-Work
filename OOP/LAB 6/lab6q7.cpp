#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, address;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);

    ofstream fout("user_info.txt");
    fout << "Name: " << name << endl;
    fout << "Address: " << address << endl;
    fout.close();

    cout << "\nData from file:\n";
    ifstream fin("user_info.txt");
    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();

    return 0;
}


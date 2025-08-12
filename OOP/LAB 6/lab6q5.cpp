#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("test.txt");
    if (file.is_open()) {
        file << "Hello, this is a test file.\n";
        file << "C++ file handling example.\n";
        file.close();
        cout << "Data written to test.txt successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
    return 0;
}

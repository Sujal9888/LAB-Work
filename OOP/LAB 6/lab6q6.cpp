#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("charfile.txt");
    char text[] = "Hello World";
    for (int i = 0; text[i] != '\0'; i++)
        fout.put(text[i]);
    fout.close();

    ifstream fin("charfile.txt");
    char ch;
    while (fin.get(ch))
        cout << ch;
    fin.close();
    return 0;
}

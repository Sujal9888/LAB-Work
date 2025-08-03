#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter number of elements in Set 1: ";
    cin >> n1;
    int set1[100];
    cout << "Enter elements of Set 1:\n";
    for (int i = 0; i < n1; i++) {
        cin >> set1[i];
    }

    cout << "Enter number of elements in Set 2: ";
    cin >> n2;
    int set2[100];
    cout << "Enter elements of Set 2:\n";
    for (int i = 0; i < n2; i++) {
        cin >> set2[i];
    }

    cout << "Cartesian Product (Set1 x Set2):\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << "(" << set1[i] << ", " << set2[j] << ") ";
        }
        cout << endl;
    }

    return 0;
}

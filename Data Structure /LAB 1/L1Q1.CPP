#include <iostream>
using namespace std;

int main() {
    int n1, n2, i, j;
    int set1[100], set2[100];
    
    cout << "Enter number of elements in Set 1: ";
    cin >> n1;
    cout << "Enter elements of Set 1:\n";
    for(i = 0; i < n1; i++) {
        cin >> set1[i];
    }
    
    cout << "Enter number of elements in Set 2: ";
    cin >> n2;
    cout << "Enter elements of Set 2:\n";
    for(i = 0; i < n2; i++) {
        cin >> set2[i];
    }
    
    cout << "Union: ";
    // Print all elements of set1 first
    for(i = 0; i < n1; i++) {
        cout << set1[i] << " ";
    }
    // Then print elements of set2 that are not in set1
    for(i = 0; i < n2; i++) {
        bool found = false;
        for(j = 0; j < n1; j++) {
            if(set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << set2[i] << " ";
        }
    }
    cout << endl;
    
    cout << "Intersection: ";
    for(i = 0; i < n1; i++) {
        for(j = 0; j < n2; j++) {
            if(set1[i] == set2[j]) {
                cout << set1[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    
    cout << "Difference (Set1 - Set2): ";
    for(i = 0; i < n1; i++) {
        bool found = false;
        for(j = 0; j < n2; j++) {
            if(set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << set1[i] << " ";
        }
    }
    cout << endl;
    
    cout << "Symmetric Difference: ";
    // Elements in set1 but not in set2
    for(i = 0; i < n1; i++) {
        bool found = false;
        for(j = 0; j < n2; j++) {
            if(set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << set1[i] << " ";
        }
    }
    // Elements in set2 but not in set1
    for(i = 0; i < n2; i++) {
        bool found = false;
        for(j = 0; j < n1; j++) {
            if(set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << set2[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

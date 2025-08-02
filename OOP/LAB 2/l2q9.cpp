#include <iostream>
using namespace std;

class FriendclassB; // Forward declaration

class FriendclassA {
private:
    int a;

public:
    FriendclassA(int x) { // Constructor to initialize 'a'
        a = x;
    }

    friend class FriendclassB; // Grant access to FriendclassB
};

class FriendclassB {
private:
    int b;

public:
    void getdata() {
        cout << "Enter value for b: ";
        cin >> b;
    }

    // Perform all mathematical operations using FriendclassA's private member
    void operate(FriendclassA objA) {
        cout << "\n--- Mathematical Operations ---\n";
        cout << "a + b = " << objA.a + b << endl;
        cout << "a - b = " << objA.a - b << endl;
        cout << "a * b = " << objA.a * b << endl;
        if (b != 0){
            cout << "a / b = " << (float)objA.a / b << endl;
        }
		else{
            cout << "Division by zero not allowed!" << endl;
		}
	}
};

int main() {
    FriendclassA objA(20);  // Initialize 'a' with constructor
    FriendclassB objB;
    objB.getdata();
    objB.operate(objA);
    return 0;
}

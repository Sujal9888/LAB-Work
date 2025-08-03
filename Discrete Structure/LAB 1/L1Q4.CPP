#include <iostream>
#include <string>

using namespace std; // Using the std namespace

struct Membership {
    int age;
    string name;
    float dom;
};

int main() {
    Membership members[50]; 
    int i = 0;

    for (i = 0; i < 5; i++) {
        cout << "Enter name and age of " << i + 1 << " person: ";
        cin >> members[i].name >> members[i].age;
        cout << endl;
    }

    for (i = 0; i < 5; i++) {
        if (members[i].age <= 20) {
            members[i].dom = 1.0f;
        } else if (members[i].age <= 30) {
            members[i].dom = (30.0f - members[i].age) / 10.0f;
        } else {
            members[i].dom = 0.0f;
        }
    }

    for (i = 0; i < 5; i++) {
        cout << "name=" << members[i].name 
                  << "\t age=" << members[i].age 
                  << "\t degree of membership=" << members[i].dom << endl;
    }

    return 0;
}

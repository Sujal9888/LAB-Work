#include <iostream>
using namespace std;

class Account {
protected:
    string customer_name;
    int account_number;
    string account_type;
    float balance;
public:
    void input() {
        cout << "Enter Customer Name: ";
        cin >> customer_name;
        cout << "Enter Account Number: ";
        cin >> account_number;
        cout << "Enter Account Type: ";
        cin >> account_type;
        balance = 0;
    }
    void deposit(float amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }
    void withdraw(float amount) {
        if(amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
    }
    void display() {
        cout << "Customer: " << customer_name
             << "\nAccount Number: " << account_number
             << "\nType: " << account_type
             << "\nBalance: " << balance << endl;
    }
};

class Saving_Account : public Account {
    // Extra functionality can be added here
};

class Current_Account : public Account {
    // Extra functionality can be added here
};

int main() {
    float amount;

    Saving_Account s;
    cout << "\n--- Enter Saving Account Details ---\n";
    s.input();
    cout << "Enter amount to deposit: ";
    cin >> amount;
    s.deposit(amount);
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    s.withdraw(amount);
    s.display();

    cout << "\n";

    Current_Account c;
    cout << "\n--- Enter Current Account Details ---\n";
    c.input();
    cout << "Enter amount to deposit: ";
    cin >> amount;
    c.deposit(amount);
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    c.withdraw(amount);
    c.display();

    return 0;
}


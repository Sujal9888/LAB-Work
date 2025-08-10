#include <iostream>
#include <string>
using namespace std;

class CentralBank {
protected:
    float ird;
    float irl;

public:
    virtual void getdata() = 0;
    virtual void displaydata() = 0;
    virtual void calculateInterestAmount(float amount) = 0;
    virtual ~CentralBank() {}
};

class NMB : public CentralBank {
public:
    void getdata()  {
        cout << "NMB Bank: " << endl;
        cout << "Enter deposit interest rate: ";
        cin >> ird;
        cout << "Enter loan interest rate: ";
        cin >> irl;
    }

    void displaydata(){
        cout << "\n--- NMB Bank Details ---\n";
        cout << "Deposit Interest Rate: " << ird << "%" << endl;
        cout << "Loan Interest Rate: " << irl << "%" << endl;
        cout << "------------------------\n";
    }

    void calculateInterestAmount(float amount)  {
        cout << "\n--- NMB Interest Calculation ---\n";
        cout << "For amount: " << amount << endl;
        cout << "Interest on deposit: " << (amount * ird / 100) << endl;
        cout << "Interest on loan: " << (amount * irl / 100) << endl;
        cout << "------------------------------\n";
    }
};

class GlobalBank : public CentralBank {
public:
    void getdata(){
        cout << "Global Bank: " << endl;
        cout << "Enter deposit interest rate: ";
        cin >> ird;
        cout << "Enter loan interest rate: ";
        cin >> irl;
    }

    void displaydata() {
        cout << "\n--- Global Bank Details ---\n";
        cout << "Deposit Interest Rate: " << ird << "%" << endl;
        cout << "Loan Interest Rate: " << irl << "%" << endl;
        cout << "--------------------------\n";
    }

    void calculateInterestAmount(float amount){
        cout << "\n--- Global Bank Interest Calculation ---\n";
        cout << "For amount: " << amount << endl;
        cout << "Interest on deposit: " << (amount * ird / 100) << endl;
        cout << "Interest on loan: " << (amount * irl / 100) << endl;
        cout << "------------------------------------\n";
    }
};

int main() {
    CentralBank* bank;

    bank = new NMB();
    bank->getdata();
    bank->displaydata();
    bank->calculateInterestAmount(10000);
    delete bank;

    cout << "\n====================================\n\n";

    bank = new GlobalBank();
    bank->getdata();
    bank->displaydata();
    bank->calculateInterestAmount(50000);
    delete bank;

    return 0;
}


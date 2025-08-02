#include <iostream>
using namespace std;

class Payment {
private:
    int billNo;
    float totalAmount;
public:
    void inputPayment() {
        cout << "Enter Bill No and Total Amount: "<<endl;
        cin >> billNo >> totalAmount;
    }
    void displayPayment() {
        cout << "Bill No: " << billNo << "\nTotal Amount: " << totalAmount << endl;
    }
};

class Ward : public Payment {
protected:
    string wardType;
    int bedNo;
public:
    void inputWard() {
        inputPayment();
        cout << "Enter Ward Type and Bed No: "<<endl;
        cin >> wardType >> bedNo;
    }
    void displayWard() {
        displayPayment();
        cout << "Ward Type: " << wardType << "\nBed No: " << bedNo << endl;
    }
};

class Patient : public Ward {
protected:
    int patientId;
    string name;
public:
    void inputPatient() {
        inputWard();
        cout << "Enter Patient ID and Name: "<<endl;
        cin >> patientId >> name;
    }
    void displayPatient() {
        displayWard();
        cout << "Patient ID: " << patientId << "\nName: " << name << endl;
    }
};

int main() {
    Patient p;
    p.inputPatient();
    cout << "\n--- Patient Details ---\n";
    p.displayPatient();
    return 0;
}

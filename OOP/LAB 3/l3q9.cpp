#include <iostream>
using namespace std;

class Dollar;

class Rupees {
public:
    int rs;
    int paisa;

    Rupees() {
        rs = 0;
        paisa = 0;
    }

    Rupees(float totalPaisa) {
        rs = static_cast<int>(totalPaisa) / 100;
        paisa = static_cast<int>(totalPaisa) % 100;
    }

    void display() {
        cout << rs << " Rupees " << paisa << " Paisa" << endl;
    }
};

class Dollar {
public:
    int dol;
    int cent;

    Dollar() {
        dol = 0;
        cent = 0;
    }

    operator Rupees() {
        float totalCents = dol * 100.0 + cent;
        const float CONVERSION_RATE_PAISA_PER_CENT = 137.36;

        float totalPaisa = totalCents * CONVERSION_RATE_PAISA_PER_CENT;

        return Rupees(totalPaisa);
    }

    void getDollar() {
        cout << "Enter dollar & cent: ";
        cin >> dol >> cent;
    }
};

int main() {
    Rupees r1;
    Dollar d1;

    d1.getDollar();

    r1 = d1;

    r1.display();

    return 0;
}


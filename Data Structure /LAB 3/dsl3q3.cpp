#include<iostream>
using namespace std;
bool implies(bool a, bool b){
	return !a||b;
	}


int main() {
    cout << "\nValidating: I will buy a goat or a Yugo...\n";
    cout << "p: buy goat, q: buy Yugo, r: need loan\n";
    cout << "p q r | pvq | (p^q) -> r | ~r ^ q | ~p\n";
    cout << "------------------------------------------\n";

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool premise1 = p || q;
                bool premise2 = implies(p && q, r);
                bool premise3 = !r && q;
                bool conclusion = !p;

                cout << p << " " << q << " " << r << " |   " << premise1
                     << "   |      " << premise2 << "     |   " << premise3
                     << "   |  " << conclusion << "\n";
            }
        }
    }

    return 0;
}


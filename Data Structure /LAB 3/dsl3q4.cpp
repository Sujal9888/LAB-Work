#include <iostream>
using namespace std;
bool implies(bool a, bool b){
	return !a||b;
	}

int main() {
    cout << "\nValidating: If I go to the mall, I will buy a shirt.\n";
    cout << "p: go to mall, q: buy jeans, r: buy shirt\n";
    cout << "p q r | p->q | q->r | p->r | (p->q ^ q->r) -> (p->r)\n";
    cout << "-------------------------------------------------\n";

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool p_imp_q = implies(p, q);
                bool q_imp_r = implies(q, r);
                bool p_imp_r = implies(p, r);
                bool whole = implies(p_imp_q && q_imp_r, p_imp_r);

                cout << p << " " << q << " " << r << " |  " << p_imp_q
                     << "   |  " << q_imp_r << "   |  " << p_imp_r
                     << "   |         " << whole << "\n";
            }
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

bool implies(bool a, bool b) {
    return !a || b;
}

bool bi_conditional(bool a, bool b) {
    return a == b;
}

int main() {
    cout << "p q r | (p ^ ~q v r) -> (~p v r) | (p ^ ~q v r) <--> (~p v r)\n";
    cout << "--------------------------------------------------------\n";

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool left = (p && !q) || r;
                bool right = (!p) || r;
                bool impl = implies(left, right);
                bool equiv = bi_conditional(left, right);

                cout << p << " " << q << " " << r << "   |        "
                     << impl << "              |           " << equiv << "\n";
            }
        }
    }

    return 0;
}

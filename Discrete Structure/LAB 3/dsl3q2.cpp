#include <iostream>
using namespace std;
bool implies(bool a, bool b){
	return !a||b;
	}

int main() {
    cout << "\nValidating: If you are a hound dog, then you howl at the moon.\n";
    cout << "You don't howl at the moon.\nTherefore, you aren't a hound dog.\n";
    cout << "p: You are a hound dog, q: You howl at the moon\n";
    cout << "p q | p -> q | ~q | ~q -> ~p\n";
    cout << "---------------------------\n";

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            bool premise = !p || q;
            bool not_q = !q;
            bool conclusion = implies(!q, !p);
            cout << p << " " << q << " |   " << premise
                 << "   |  " << not_q << "  |     " << conclusion << "\n";
        }
    }

    return 0;
}

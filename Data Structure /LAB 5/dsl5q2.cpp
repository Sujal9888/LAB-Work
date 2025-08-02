#include <iostream>

bool nextCombination(int comb[], int n, int r) {
    int i = r - 1;

    // Find the rightmost element that can be incremented
    while (i >= 0 && comb[i] == n - r + i)
        i--;

    if (i < 0)
        return false; // No more combinations

    comb[i]++;

    // Set following elements to maintain increasing order
    for (int j = i + 1; j < r; j++)
        comb[j] = comb[j - 1] + 1;

    return true;
}

int main() {
    int n = 5; // Total elements in the set
    int r = 3; // Size of each combination

    int comb[r];
    for (int i = 0; i < r; i++) comb[i] = i;

    do {
        std::cout << "{ ";
        for (int i = 0; i < r; i++)
            std::cout << comb[i] << " ";
        std::cout << "}" << std::endl;
    } while (nextCombination(comb, n, r));

    return 0;
}

#include <iostream> // Required for input/output operations
#include <string>   // Required for std::string

// Using the 'std' namespace to avoid prefixing standard library elements with 'std::'
using namespace std;

/**
 * @brief Solves the Tower of Hanoi puzzle recursively and prints the moves.
 *
 * @param n The number of disks to move.
 * @param source The name of the source peg (e.g., "Peg A").
 * @param destination The name of the destination peg (e.g., "Peg C").
 * @param auxiliary The name of the auxiliary (temporary) peg (e.g., "Peg B").
 */
void solveTowerOfHanoi(int n, const string& source,
                       const string& destination,
                       const string& auxiliary) {
    // Base case: If there's only one disk, simply move it directly.
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return; // End the recursion for this branch
    }

    // Recursive steps:

    // 1. Move the top n-1 disks from the source peg to the auxiliary peg.
    //    The destination peg is used as temporary storage during this step.
    solveTowerOfHanoi(n - 1, source, auxiliary, destination);

    // 2. Move the nth disk (the largest disk remaining on the source peg)
    //    from the source peg directly to the destination peg.
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // 3. Move the n-1 disks from the auxiliary peg to the destination peg.
    //    The original source peg is now used as temporary storage.
    solveTowerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int numberOfDisks = 10; // Define the number of disks for the puzzle

    cout << "--- Tower of Hanoi Puzzle Solver ---\n";
    cout << "Number of Disks: " << numberOfDisks << "\n\n";
    cout << "Starting with disks on Peg A, moving to Peg C, using Peg B as auxiliary.\n";
    // Calculate total moves required: 2^n - 1. (1 << numberOfDisks) is a bit shift for 2^n.
    cout << "Total moves required: " << (1 << numberOfDisks) - 1 << "\n\n";

    // Initiate the puzzle solving process.
    // Call the function with the initial state:
    // All 'numberOfDisks' are on "Peg A (Source)".
    // They need to be moved to "Peg C (Destination)".
    // "Peg B (Auxiliary)" will be used as intermediate storage.
    solveTowerOfHanoi(numberOfDisks, "Peg A (Source)", "Peg C (Destination)", "Peg B (Auxiliary)");

    cout << "\n--- Puzzle Solved! All disks are on Peg C. ---\n";

    return 0; // Indicate successful program execution.
}

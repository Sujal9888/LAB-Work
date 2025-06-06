#include <iostream>


int main() {
    // Using the :: operator
    std::cout << "--- Using :: operator ---" << std::endl;
    std::cout << "Enter an integer using :: operator: ";
    int num_op;
    std::cin >> num_op;
    std::cout << "You entered: " << num_op << std::endl;
    std::cout << std::endl;

    // Using declaration
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "--- Using declaration ---" << endl;
    cout << "Enter an integer using using declaration: ";
    int num_decl;
    cin >> num_decl;
    cout << "You entered: " << num_decl << endl;
    cout << endl;

    // Using directive (names already available from top 'using namespace std;')
    cout << "--- Using directive ---" << endl;
    cout << "Enter an integer using using directive: ";
    int num_dir;
    cin >> num_dir;
    cout << "You entered: " << num_dir << endl;

    return 0;
}

#include <iostream>
#include <limits>

using namespace std;

int main() {
    int scores[5];
    int sum = 0;
    double average;
    char grade;

    cout << "Enter scores for 5 papers (0-100):" << endl;

    for (int i = 0; i < 5; ++i) {
        while (true) {
            cout << "Paper " << (i + 1) << ": ";
            cin >> scores[i];

            if (cin.fail() || scores[i] < 0 || scores[i] > 100) {
                cout << "Invalid score. Please enter a number between 0 and 100." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                sum += scores[i];
                break;
            }
        }
    }

    average = static_cast<double>(sum) / 5;

    int average_scaled = static_cast<int>(average / 10);

    switch (average_scaled) {
        case 10:
        case 9:
        case 8:
            grade = 'A';
            break;
        case 7:
        case 6:
            grade = 'B';
            break;
        case 5:
            grade = 'C';
            break;
        case 4:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }

    cout << "\n--- Student Report ---" << endl;
    cout << "Total Score: " << sum << endl;
    cout << "Average Score: " << average << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}

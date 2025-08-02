#include <iostream>

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverse(char str[], int start, int end) {
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

bool nextPermutation(char str[], int length) {
    int i = length - 2;

    // Step 1: Find longest non-increasing suffix
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }

    if (i < 0) return false; // Already at highest permutation

    // Step 2: Find rightmost character that exceeds str[i]
    int j = length - 1;
    while (str[j] <= str[i]) {
        j--;
    }

    // Step 3: Swap the pivot
    swap(str[i], str[j]);

    // Step 4: Reverse the suffix
    reverse(str, i + 1, length - 1);

    return true;
}

int main() {
    char str[] = "abc";
    int length = sizeof(str) / sizeof(str[0]) - 1; // subtracting null character

    std::cout << "Current permutation: " << str << std::endl;

    if (nextPermutation(str, length)) {
        std::cout << "Next permutation: " << str << std::endl;
    } else {
        std::cout << "No next permutation (already at highest)." << std::endl;
    }

    return 0;
}

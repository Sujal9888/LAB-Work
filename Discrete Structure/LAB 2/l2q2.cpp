#include <iostream>
#include <bitset>
using namespace std;

string binaryAdd(string a, string b) {
    int n = max(a.size(), b.size());
    while (a.size() < n) a = '0' + a;
    while (b.size() < n) b = '0' + b;

    string result = "";
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }
    if (carry) result = '1' + result;
    return result;
}

string binaryMultiply(string a, string b) {
    int n = a.size();
    bitset<32> A(a), B(b);
    bitset<32> result;

    for (int i = 0; i < n; ++i) {
        if (B[i]) {
            result ^= (A << i);
        }
    }
    return result.to_string();
}

int main() {
    string a = "1011"; // 11
    string b = "1101"; // 13
    cout << "Addition: " << binaryAdd(a, b) << endl;
    cout << "Multiplication: " << binaryMultiply(a, b) << endl;
    return 0;
}

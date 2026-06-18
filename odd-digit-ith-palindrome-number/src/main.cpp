
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long generatePalindrome(int i) {
    // Convert i to string for manipulation
    string original = to_string(i);

    // Step 1: Remove the least significant digit from original i
    string truncated = original.substr(0, original.size() - 1);

    // Step 2: Reverse the digits of the original number
    string reversed = original;
    reverse(reversed.begin(), reversed.end());

    // Step 3: Concatenate reversed with truncated
    string palindrome = truncated + reversed;

    // Convert the concatenated string back to a number
    return stoll(palindrome);
}

int main() {
    int i;
    cout << "Enter the value of i: ";
    cin >> i;

    if (i <= 0) {
        cout << "Invalid input. i should be a positive integer." << endl;
        return 1;
    }

    long long result = generatePalindrome(i);
    cout << "Generated number: " << result << endl;

    return 0;
}
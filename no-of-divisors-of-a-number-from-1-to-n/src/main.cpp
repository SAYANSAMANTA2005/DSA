#include <iostream>
#include <vector>
using namespace std;

vector<int> findDivisors(int n) {
    vector<int> divisors(n + 1, 0); // Initialize divisor counts to 0
    
    // Iterate through each number from 1 to n
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divisors[j]++; // Increment divisor count for all multiples of i
        }
    }
    return divisors;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> divisors = findDivisors(n);

    cout << "Number of divisors for each number from 1 to " << n << ":\n";
    for (int i = 1; i <= n; ++i) {
        cout << "Number " << i << " has " << divisors[i] << " divisors.\n";
    }

    return 0;
}
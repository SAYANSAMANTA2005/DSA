#include <iostream>
#include <vector>
using namespace std;

vector<int> computeTotient(int n) {
    vector<int> phi(n + 1);

    // Step 1: Initialize φ[i] = i
    for (int i = 1; i <= n; ++i) {
        phi[i] = i;
    }

    // Step 2: Update φ values using the sieve approach
    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) { // i is a prime number
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i; // Update multiples of i
            }
        }
    }

    return phi;
}

int main() {
    int n;
    cout << "Enter the range (n): ";
    cin >> n;

    vector<int> phi = computeTotient(n);

    cout << "Euler's Totient Function values for range 1 to " << n << ":\n";
    for (int i = 1; i <= n; ++i) {
        cout << "φ(" << i << ") = " << phi[i] << endl;
    }

    return 0;
}
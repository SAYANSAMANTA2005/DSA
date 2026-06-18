#include <iostream>
using namespace std;

int phi(int n) {
    int result = n; // Start with φ(n) = n
    for (int p = 2; p * p <= n; ++p) {
        // Check if p is a factor of n
        if (n % p == 0) {
            // If p divides n, divide out all factors of p from n
            while (n % p == 0) {
                n /= p;
            }
            // Update result for this prime factor
            result -= result / p;
        }
    }
    // If n is still greater than 1, it is a prime factor
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Euler's Totient Function value for " << n << " is " << phi(n) << endl;
    return 0;
}
#include <iostream>
#include <cmath> // For sqrt()

void primeFactors(int n) {
    // Handle number of 2s that divide n
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n /= 2;
    }

    // n must be odd at this point, so we can skip even numbers (i.e., step by 2)
    for (int i = 3; i <= sqrt(n); i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
        //first num that divides is a prime num
            std::cout << i << " ";
            n /= i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        std::cout << n << " ";
    }
}

int main() {
    int n = 81; // Example input
    std::cout << "Prime factors of " << n << " are: ";
    primeFactors(n);
    return 0;
}
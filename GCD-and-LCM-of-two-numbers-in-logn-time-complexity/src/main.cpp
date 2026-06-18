#include <iostream>
#include <cmath> // For abs()

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        std::swap(a, b); // This swaps a and b
    }
    return a;
}

// Function to calculate LCM
int lcm(int a, int b) {
    return std::abs(a * b) / gcd(a, b);
}

int main() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    int gcd_value = gcd(a, b);
    int lcm_value = lcm(a, b);

    std::cout << "GCD of " << a << " and " << b << " is: " << gcd_value << std::endl;
    std::cout << "LCM of " << a << " and " << b << " is: " << lcm_value << std::endl;

    return 0;
}
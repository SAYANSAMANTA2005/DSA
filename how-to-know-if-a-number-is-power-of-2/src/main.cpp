#include <iostream>

bool isPowerOfTwo(int n) {
    // Return false if the number is less than or equal to 0
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int number = 16;
    if (isPowerOfTwo(number)) {
        std::cout << number << " is a power of 2." << std::endl;
    } else {
        std::cout << number << " is not a power of 2." << std::endl;
    }
    return 0;
}
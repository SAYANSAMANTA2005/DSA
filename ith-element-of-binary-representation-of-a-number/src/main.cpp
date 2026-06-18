#include <iostream>
using namespace std;

int checkIthBit(int number, int i) {
    // Create a mask by shifting 1 to the ith position
    int mask = 1 << i;
    // Perform bitwise AND with the number and mask
    if (number & mask) {
        return 1;  // The ith bit is 1
    } else {
        return 0;  // The ith bit is 0
    }
}

int main() {
    int number = 13;  // Binary: 1101
    int i = 2;  // Check the 2nd bit (from right, starting at 0)

    int result = checkIthBit(number, i);
    cout << "The " << i << "th bit is: " << result << endl;

    return 0;
}
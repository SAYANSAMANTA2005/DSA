#include <iostream>
using namespace std;

int findRightmostSetBit(int number) {
    return number & -number;
}

int main() {
    int number = 18; // Binary: 10010
    int result = findRightmostSetBit(number);
    cout << "Rightmost set bit of " << number << " is: " << result << endl;
    return 0;
}
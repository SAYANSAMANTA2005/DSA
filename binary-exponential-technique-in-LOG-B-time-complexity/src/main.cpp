#include <iostream>
using namespace std;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    
    int tmp = power(a, b / 2);
    int result = tmp * tmp;
    
    if (b % 2 == 1) {
        result *= a;
    }
    
    return result;
}

int main() {
    int base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    
    int result = power(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;
    
    return 0;
}
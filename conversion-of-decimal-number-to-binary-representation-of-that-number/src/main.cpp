
#include <iostream>
#include <bitset>

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Convert to binary using std::bitset
    std::bitset<32> name_variable(number);
    //binary representation stores in that "name_variable"
    

    std::cout << "Binary representation: " << name_variable << std::endl;

    return 0;
}
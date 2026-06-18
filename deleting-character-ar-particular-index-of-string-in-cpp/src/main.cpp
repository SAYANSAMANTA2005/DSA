#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // Index to remove
    int index = 7;
    
    // Check if index is valid
    if (index >= 0 && index < str.length()) {
        str.erase(index, 1); // Erase one character at the specified index
    }

    std::cout << "Modified string: " << str << std::endl;

    return 0;
}
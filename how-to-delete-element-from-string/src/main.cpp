#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    int index = 7;  // The index of the character you want to delete

    // Delete the character at the specified index
    str.erase(index, 1);

    std::cout << str << std::endl;  // Output: "Hello, orld!"
    return 0;
}
#include <iostream>
#include <string>

int main() {
    std::string str1 = "HelloWorld";
    std::string str2 = "HelloUniverse";
    
    // Define the starting index and length for the substrings
    int start1 = 0, length1 = 5;  // Substring from str1
    int start2 = 0, length2 = 5;  // Substring from str2
    
    // Extract the substrings
    std::string substr1 = str1.substr(start1, length1);
    std::string substr2 = str2.substr(start2, length2);
    
    // Compare the substrings
    if (substr1 == substr2) {
        std::cout << "The substrings are equal." << std::endl;
    } else {
        std::cout << "The substrings are not equal." << std::endl;
    }
    
    return 0;
}
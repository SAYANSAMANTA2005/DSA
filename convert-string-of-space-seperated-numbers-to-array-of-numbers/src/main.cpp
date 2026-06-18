
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter space-separated numbers: ";
    std::getline(std::cin, input);  // Get the entire line of input

    std::vector<int> numbers;
    std::stringstream ss(input);  // Create a stringstream object

    int number;
    // Extract numbers from the stringstream and add to the vector
   while (ss >> number) {
        numbers.push_back(number);
    }

    // Output the numbers array
    std::cout << "Converted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
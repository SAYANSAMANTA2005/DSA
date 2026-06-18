#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> numbers,sec;
numbers={10,20,30,40};
    // Adding elements to the vector
    
sec=numbers ;
    // use a range-based for loop
    std::cout << "Using range-based for loop: ";
    for (int num : sec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
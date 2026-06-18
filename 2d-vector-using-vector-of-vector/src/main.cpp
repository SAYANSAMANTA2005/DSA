#include <iostream>
#include <vector>

int main() {
    // Define a vector of vectors of integers
    std::vector<std::vector<int>> vec;

    // Initialize the vector with some values
    vec.push_back({1, 2, 3});
    vec.push_back({4, 5, 6});
    vec.push_back({7, 8, 9});

    // Access and modify elements
    vec[0][1] = 20;// Change the value at row 0, column 1 to 20

    // Print the elements of the vector of vectors
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
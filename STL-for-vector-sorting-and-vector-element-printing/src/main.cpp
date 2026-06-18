#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

int main() {
    std::vector<int> vec = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Unsorted vector: ";
    for (int i: vec) {
    //for printing all elements of vector 
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Using std::sort to sort the vector
    std::sort(vec.begin(), vec.end());

    std::cout << "Sorted vector: ";
    for (int i=0;i<vec.size();i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
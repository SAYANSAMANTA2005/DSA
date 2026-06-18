#include <iostream>
#include <set>
#include <tuple>

int main() {
    // Define a set of triplets (tuple of three integers)
    std::set<std::tuple<int, int, int>> tripletSet;

    // Insert some triplets into the set
    tripletSet.insert(std::make_tuple(1, 2, 3));
    tripletSet.insert(std::make_tuple(4, 5, 6));
    tripletSet.insert(std::make_tuple(1, 2, 3)); // Duplicate, won't be added

    // Iterate and display the elements of the set
    for (const auto& triplet : tripletSet) {
        std::cout << "("
                  << std::get<0>(triplet) << ", "
                  << std::get<1>(triplet) << ", "
                  << std::get<2>(triplet) << ")\n";
    }

    return 0;
}
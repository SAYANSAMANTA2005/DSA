#include <iostream>
#include <numeric>  // For accumulate
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Using accumulate to calculate the sum
    int sum = accumulate(arr, arr + n, 0);

    // Print the sum
    cout << "Sum of the elements in the array: " << sum << endl;

    return 0;
}
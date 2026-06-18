
#include<bits/stdc++.h>
using namespace std;


void printPermutations(std::vector<int>& arr) {

    do {
        // Print the current permutation
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    } 
    while (next_permutation(arr.begin(), arr.end()));
}

int main() {
    
    vector<int> arr = {1, 2, 3};

    cout << "All permutations of the array are:" << endl;
    printPermutations(arr);

    return 0;
}
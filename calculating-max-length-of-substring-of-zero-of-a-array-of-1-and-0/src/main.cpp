#include <iostream>
#include <vector>
using namespace std;

int maxLengthOfZeros(const vector<int>& arr) {
    int max_length = 0;
    int current_length = 0;

    for (int num : arr) {
        if (num == 0) {
            current_length++;
        } else {
            max_length = max(max_length, current_length);
            current_length = 0;
        }
    }

    // Check one last time in case the array ends with a sequence of 0s
    max_length = max(max_length, current_length);

    return max_length;
}

int main() {
    vector<int> arr = {1, 0, 0, 1, 0, 0, 0, 1, 0};
    cout << "Maximum length of 0s: " << maxLengthOfZeros(arr) << endl;
    return 0;
}
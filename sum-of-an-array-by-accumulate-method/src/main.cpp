#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int start = 1;
    int end = 3;

    int sum = accumulate(arr + start, arr + end + 1, 0);

    cout << "Sum of the segment is: " << sum << endl;
    return 0;
}
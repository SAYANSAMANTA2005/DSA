#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for intervals
struct Interval {
    int start, end;
};

// Comparator to sort intervals by their end time
bool compareInterval(Interval i1, Interval i2) {
    return (i1.end < i2.end);
}

// Function to perform interval scheduling using a greedy algorithm
int intervalScheduling(vector<Interval> &intervals) {
    // Sort intervals by their end time
    sort(intervals.begin(), intervals.end(), compareInterval);

    // The last selected interval's end time
    int lastEndTime = -1;

    // Number of non-overlapping intervals
    int count = 0;

    // Iterate through the sorted intervals
    for (auto interval : intervals) {
        // If the current interval starts after the last selected interval ends
        if (interval.start >= lastEndTime) {
            // Select the current interval
            lastEndTime = interval.end;
            count++;
        }
    }

    return count;
}

int main() {
    // Example set of intervals
    vector<Interval> intervals = { {1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9} };

    // Perform interval scheduling
    int result = intervalScheduling(intervals);
     
    // Output the result
    cout << "The maximum number of non-overlapping intervals is: " << result << endl;

    return 0;
}
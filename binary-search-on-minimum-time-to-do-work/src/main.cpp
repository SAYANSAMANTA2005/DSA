#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to finish all tasks in 'maxTime'
bool canFinishTasks(vector<int>& workers, int tasks, long long maxTime) {
    long long totalTasks = 0;
    for (int time : workers) {
        totalTasks += maxTime / time; // Tasks each worker can complete
        if (totalTasks >= tasks) return true; // Enough tasks completed
    }
    return totalTasks >= tasks;
}

long long findMinimumTime(vector<int>& workers, int tasks) {
    long long low = 1, high = 1e18, result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canFinishTasks(workers, tasks, mid)) {
            result = mid;  // Try for a smaller time
            high = mid - 1;
        } else {
            low = mid + 1; // Increase time
        }
    }
    return result;
}

int main() {
    vector<int> workers = {1, 2, 3}; // Time each worker takes to complete a task
    int tasks = 10;                  // Number of tasks to complete
    cout << "Minimum time to finish tasks: " << findMinimumTime(workers, tasks) << endl;
    return 0;
}
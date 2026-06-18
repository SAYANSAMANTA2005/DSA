#include <iostream>
#include <queue>
using namespace std;

// Custom comparator (greater element has lower priority)
struct Compare {
    bool operator()(int a, int b) {
        return a % 10 > b % 10; // Compare based on last digit
    }
};

int main() {
    // Priority queue with custom comparator
    priority_queue<int, vector<int>, Compare> pq;

    // Insert elements
    pq.push(37);
    pq.push(42);
    pq.push(19);
    pq.push(85);

    // Display and remove elements
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
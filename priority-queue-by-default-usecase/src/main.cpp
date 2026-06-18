#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Priority queue (max-heap by default)
    priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(20);
    pq.push(15);

    // Display and remove elements
    while (!pq.empty()) {
        cout << pq.top() << " "; // Top element (largest)
        pq.pop(); // Remove the top element
    }
    return 0;
}
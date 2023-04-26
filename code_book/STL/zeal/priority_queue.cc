#include <iostream>
#include <queue>

int main() {
    // create a priority queue of integers
    std::priority_queue<int> pq;

    // insert some elements into the priority queue
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);

    // print the elements in the priority queue
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    std::cout << std::endl;
    return 0;
}

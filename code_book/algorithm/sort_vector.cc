#include <iostream>
#include <vector>
#include <algorithm>

void sortVector(std::vector<int>& v) {
    // Step 1: sort the vector
    std::sort(v.begin(), v.end());

    // Step 2: swap the first and last elements
    std::swap(v.front(), v.back());

    // Step 3: if size is odd, swap middle element with second element from end
    if (v.size() % 2 == 1) {
        std::swap(v[v.size()/2], v[v.size()-2]);
    }
}

int main() {
    std::vector<int> v = { 5, 2, 7, 1, 9, 3, 8, 4, 6 };
    // sortVector(v);
    std::sort(v.begin(), v.end());
    std::swap(v[v.size() - 1], v[v.size() / 2]);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
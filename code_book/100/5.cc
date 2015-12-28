// 5.cc
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 查找最小的k个数
typedef multiset<int, greater<int> > max_heap;
void find_k_least(const vector<int>& data, max_heap& heap, size_t k) {
    heap.clear();

    if(k == 0 || data.size() < k)
        return;

    vector<int>::const_iterator it;
    for(it = data.begin(); it != data.end(); ++ it) {
        if((heap.size()) < k)
            heap.insert(*it);
        else {
            max_heap::iterator it_first = heap.begin();  // 最大元素
            if(*it < *it_first) {  // 比堆中的最大元素小
                heap.erase(it_first);
                heap.insert(*it);
            }
        }
    }
}

int main() {
    vector<int> data;
    for (int i = 10; i > 0; i--)
        data.push_back(i);
    size_t k = 4;
    max_heap heap;
    find_k_least(data, heap, k);

    max_heap::const_iterator it;
    for (it = heap.begin(); it != heap.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
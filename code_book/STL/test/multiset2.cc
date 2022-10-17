#include <iostream>
#include <iterator>
#include <set>
#include <string>
 
int main()
{
    const std::multiset<int> words = {
        1, 2, 4, 7,
        6, 3, 2, 5,
    };
 
    for (auto it = words.begin(); it != words.end(); ) {
        auto cnt = words.count(*it);
        std::cout << *it << ":\t" << cnt << '\n';
        std::advance(it, cnt); // all cnt elements have equivalent keys
    }
}
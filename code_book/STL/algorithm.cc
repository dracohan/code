/* algorithm.cc
*  2014/09/02 update
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

void print(int elem) {
    cout << elem << endl;
}

int main() {
    vector<int> v;
    vector<int>::iterator pos;

    for(int i = 6; i >= 1; i--)
        v.push_back(i);

    //max_element
    pos = max_element(v.begin(), v.end());
    cout << "the max element is: " << *pos << endl;
    //min_element
    pos = min_element(v.begin(), v.end());
    cout << "the min element is: " << *pos << endl;
    
    //sort
    sort(v.begin(), v.end());

    //find
    pos = find(v.begin(), v.end(), 3);

    //reverse
    reverse(pos, v.end());

    for(pos = v.begin(); pos != v.end(); pos++)
        cout << "Content of vector: " << *pos << " " << endl;

    //copy
    vector<int> v2;
    vector<int>::iterator pos1;
    
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());
    cout << "Pre:" << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));

    //remove
    vector<int>::iterator end = remove(v2.begin(), v2.end(), 5);
    cout << endl << "After remove(v2.begin(), v2.end(), 5) : " << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    v2.erase(end, v2.end());
    cout << endl << "After erase(end, v2.end()) : " << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //也可以使用v2.erase(remove(v2.begin(), v2.end(), 5), v2.end()))

    //for_each()
    cout << "cout from for_each():" << endl;
    for_each(v2.begin(), v2.end(), print);

    return 0;
}
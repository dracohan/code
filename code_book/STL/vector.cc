/* vector.cc
*  2014/09/02 update
*/
#include <vector>
#include <iostream>
#include <iterator>
#include "../utility/printCollection.h"
using namespace std;

int ia[] = {1,2,3,4,5,6,7,8,9,10, 11,12};

int main() {
    //initialize
    vector<int> vint1;
    vector<int> vint2(ia, ia+10);
    printCollection(vint2, "0: ");
    //push_back()
    for(int i = 0; i <=6; ++i)
        vint1.push_back(i);

    //no push_front()
    //vint1.push_front(222);

    //size()
    cout << "The size of vint1 is: " << vint1.size() << endl;

    //[] operator
    for(int i = 0; i < vint2.size(); i++)
        cout << vint2[i] << endl;

    vint2.erase(vint2.begin()+3, vint2.end());

    copy(vint2.begin(), vint2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //COMMON操作，每个容器都支持
    //空构造函数
    vector<int> vec;
    printCollection(vec, "1: ");
    //拷贝构造函数
    vector<int> vec2(vec);
    printCollection(vec2, "2: ");
    //赋值构造
    vector<int> vec3(vint1.begin(), vint1.begin() + 4);
    printCollection(vec3, "3: ");
    //swap
    vec2.swap(vec3);
    printCollection(vec2, "4: ");
    //insert
    vec2.insert(vec2.begin()+1, 22);
    printCollection(vec2, "5: ");
    //erase
    vec2.erase(vec2.begin() + 2);
    printCollection(vec2, "6: ");
    //clear
    vec2.clear();
    printCollection(vec2, "7: ");


    return 0;
}


#include <iostream>
#include "Sort.h"
#include "../utility/printCollection.h"
#include <vector>

using namespace std;

int main( )
{   
    vector<int> intv;
    intv.push_back(31);
    intv.push_back(41);
    intv.push_back(59);
    intv.push_back(26);
    intv.push_back(17);
    intv.push_back(28);
    intv.push_back(72);
    intv.push_back(71);
    printCollection(intv);
    insertionSort(intv);
    printCollection(intv);

    return 0;
}

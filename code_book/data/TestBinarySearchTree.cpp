#include <iostream>
#include "BinarySearchTree.h"
#include "../own/printCollection.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;

    t.insert(9);
    t.insert(7);
    t.insert(5);
    t.insert(3);
    t.insert(2);
    t.insert(10);
    t.insert(8);
    t.insert(6);
    t.insert(4);
    t.printTree();
printCollection(t.vint);




    return 0;
}

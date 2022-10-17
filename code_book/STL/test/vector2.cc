
// CPP program to illustrate swapping
// of two vectors using std::swap()
 
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 5, 6 };
 
    // swapping the above two vectors
    // by traversing and swapping each element
    v1 = v2;

    // print vector v1
    cout << "Vector v1 = ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
 
    cout << "\nVector v1 size = " << v1.size();

    // print vector v2
    cout << "\nVector v2 = ";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }

	
    cout << "\nVector v2 size = " << v2.size();
 
    return 0;
}

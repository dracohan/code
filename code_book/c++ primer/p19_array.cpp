/*
 * Purpose: array  
 * Date: 2013/06/06
 * Page: p19 
 */
#include <iostream>
#include <vector>

using namespace std;

int main () 
{
    //code start here
    vector< int > vec;

    for(int i = 0; i <= 9 ; i++)
        vec.push_back(i);

    vector< int >::iterator iter = vec.end() -1;

    for( ; iter != vec.begin(); iter--)
        cout << *iter << " ";
    
    cout << endl;

    return 0;
}


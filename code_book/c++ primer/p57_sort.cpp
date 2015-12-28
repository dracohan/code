/*
 * Purpose: sort function usage
 * Date: 2013/06/09 
 * Page: 57 
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ia[] = { 1, 13, 25, 11, 109, 2, 4, 8, 10 };

int main () 
{
    //code start here
    vector<int> ivec( ia, ia+9 );
    int search_int; 
    vector<int>::iterator iter = ivec.begin();
    vector<int>::iterator found; 
    
    while( iter != ivec.end() ) {
        cout << *iter << " ";
        iter += 1;
    }

    cout << endl << "Please enter the int to search for: " << endl;
    cin >> search_int;
    
    found = find( ivec.begin(), ivec.end(), search_int );
    
    if ( found != ivec.end() )
        cout << search_int << " was found. " << endl;
    else cout << "search value not found. " << endl;

    reverse( ivec.begin(), ivec.end() );

    iter = ivec.begin();
    while( iter != ivec.end() ) {
        cout << *iter << " ";
        iter += 1;
        }
    
    return 0;

}


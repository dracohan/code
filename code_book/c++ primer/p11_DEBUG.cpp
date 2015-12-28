/*
 * Purpose: DEBUG usage 
 * Date: 2013/06/06
 * Page: 11
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main () 
{
#ifdef DEBUG
    cout << "Begin the execution of main" << endl;
#endif
    string word;
    vector< string > StorageString;  
    
    while( cin >> word )
    {
#ifdef DEBUG
        cout << "The input word is: " << word << endl;
#endif
        StorageString.push_back( word );
    }

    vector< string >::iterator iter = StorageString.begin();

    for( int i = 0; iter != StorageString.end(); i++, iter++)
        cout << " The string of index: " << i << " is " << *iter << endl;

    return 0;
}


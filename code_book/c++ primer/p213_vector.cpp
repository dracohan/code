/*
 * Purpose: Use vector, list, deque, string, map, set
 * Date: 2013/06/13
 * Page: 213
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main () 
{
    //code start here
    vector<int> ivec;
    cout << "Capacity is : " << ivec.capacity() << endl;
    
    ivec.reserve( 100 );
        
    for ( int ix = 0; ix < 101; ++ix )
    	ivec.push_back( ix ); 
    
    cout << " Size of ivec is : " << ivec.size()
    	<< " Capacity of ivec is : " << ivec.capacity() << endl;
    	
	vector<string> svec( 12, "poeh" );
	string text_word;
	
	
	cout << " Size of svec is : " << svec.size()
    	<< " Capacity of svec is : " << svec.capacity() << endl;
    
    cout << " Size of svec is : " << svec.size()
    	<< " Capacity of svec is : " << svec.capacity() << endl;

    while( cin >> text_word )
    	svec.push_back( text_word );
    
    svec.resize( 2*svec.size() );
    
    string spouse( "Beth" );
    svec.insert( svec.begin(), spouse );
    svec.insert( svec.begin()+2, 2, spouse );
    
    	
    vector<string>::iterator iter = svec.begin();
    vector<string>::iterator iter_end = svec.end();
    
    
    for( int ix = 0; iter != iter_end; iter++, ix++ )
    	cout <<" " << ix << ": " << *iter << ", ";
    	
    cout << endl;
    
    vector<string> svec2( svec.begin(), svec.end() );
    vector<string>::iterator it = 
    svec.begin() + svec.size()/2;
    vector<string> svec3( svec.begin(), it );
    
    vector<string>::iterator siter = svec3.begin();
    
    for( int ix = 0; siter != svec3.end(); siter++, ix++ )
    	cout <<"svec3 " << ix << ": " << *siter << ", ";
    
    	
    cout << endl;
    
    
    
    	
    	
    
}


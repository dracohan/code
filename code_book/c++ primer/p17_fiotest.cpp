/*
 * Purpose: 
 * Date: 
 * Page: 
 */
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

int main () 
{
    //code start here
    ofstream outfile( "out_file" );
    ifstream infile( "in_file");
    string word;

    if( !outfile )
        cerr << "Unable to open file out_file!" << endl;

    if( !infile )
        cerr << "Unable to open file in_file" << endl;

    while( infile >> word)
        outfile << word << "\n";
    
    return 0;

}


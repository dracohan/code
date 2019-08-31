/*
 * Purpose: prepare function call
 * Date: 2013/06/06 
 * Page: 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () 
{
    //code start here
    ifstream infile("pmcheck");
    ofstream outfile("pmcheck_out");
    vector<string> vec;
    string word;

    if( !infile )
        cerr << "Unable to open pmcheck!" << endl;

    while ( infile >> word ) {
        if ( word == "" || word == "\t" || word == "\n")
            continue;
        vec.push_back(word);
    }
    
    vector<string>::iterator iter = vec.begin();

    while ( iter != vec.end() ) {
        outfile << "res = row_fill( \"" << *iter << "\", " 
            << "\"" << *(iter + 1) << "\", " 
            << "\"" << *(iter + 2) << "\", " 
            << "\"" << *(iter + 3) << "\", "
            << "\"" << *(iter + 4) << "\" )" << endl; 
        iter += 5; 
    }
}


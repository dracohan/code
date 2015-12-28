#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_RECORD_NUM = 20000;

int replace_str(string& sline1, string& sline2, int targetcolumn)
{
    size_t start_pos = 0; 
    size_t end_pos = 0; 
    int column = 1;
    
    while(((start_pos = sline1.find(",", start_pos)) != string::npos) && (column != targetcolumn - 1))
    { 
        column++;
        start_pos = start_pos + 1;
    }

    end_pos = sline1.find(",", start_pos + 1);

    sline1.replace(start_pos+1, (end_pos - start_pos - 1), sline2); 

    return 0;
}

void usage()
{
    //usage
    cout << "###################################################################" << endl;
    cout << "# Usage example: " << endl;
    cout << "# $ ./columntransfer.exe" << endl;
    cout << "# Please enter the filename with old column content:" << endl;
    cout << "# a.csv" << endl;
    cout << "# Please enter the filename with new column content:"<< endl;
    cout << "# column.txt" << endl;
    cout << "# Please enter the target column number, etc: 18:" << endl;
    cout << "# 18" << endl;
    cout << "# Target file with new column content was generated at: a.csv_new." << endl;
    cout << "###################################################################" << endl;
    cout << endl;
    cout << endl;

}


int main() {

    usage();

    cout << "Please enter the filename with old column content: " << endl;
    string filename1;
    cin >> filename1;

    cout << "Please enter the filename with new column content: " << endl;
    string filename2;
    cin >> filename2;

    cout << "Please enter the target column number, etc: 18: " << endl;
    int targetcolumn;
    cin >> targetcolumn;
   
    string filename3 = filename1 + "new";

    ifstream infile1(filename1.c_str());
    if(!infile1)
        cerr << "Error when opening" << filename1;

    ifstream infile2(filename2.c_str());
    if(!infile2)
        cerr << "Error when opening" << filename2;
    
    ofstream outfile(filename3.c_str());
    if(!outfile)
        cerr << "Error when opening" << filename3;

    string sline1;
    string sline2;

    for( int i = 1; i <= MAX_RECORD_NUM; i++ )
    {
        while(getline(infile1, sline1))
        {
            getline(infile2, sline2);
            
            //erase the ending newline
            sline2.erase(sline2.size() - 1);
           
            //replace the column
            replace_str(sline1, sline2, targetcolumn);
            
            //write into output file
            outfile << sline1 << endl;

            //next line
            break;
        }
    }

    cout << "Target file with new column content was generated at: " << (filename1+"_new") << "." << endl;
    return 0;
}



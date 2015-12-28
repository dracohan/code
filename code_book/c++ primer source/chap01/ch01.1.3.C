// #include <iostream>

#include <iostream.h>
#include <vector>
#include <string>
#include <assert.h>
#include <fstream>
using namespace std;
/**
 **
 CC -n32 -experimental -I $EXTERN/include -DDEBUG ch01.1.3.c $EXTERN/lib32/libstd.so
 a.out < input_file
 Beginning execution of main()
 word read: Shyly,
 word read: she
 word read: asks,
 word read: "I
 word read: mean,
 word read: Daddy,
 word read: is
 word read: there?"
 **
 **/

int main()
{

#ifdef DEBUG
	cout << "Beginning execution of main()\n";
#endif

 	string word;
 	vector< string > text;

 	while ( cin >> word )
 	{
#ifdef DEBUG
  		cout << "word read: " << word << "\n";
#endif

  		text.push_back( word );
 	}

 	// JM code start
 	//check __cplusplus macro
 	#ifdef __cplusplus
 	cout << "__cplusplus is defined!" << endl;
 	#else 
 	cout << "__cplusplus is NOT defined!" << endl;
 	#endif

 	//check __FILE__ and __LINE__ macro
 	cerr <<"Error: " << __FILE__
 		<< " at line " << __LINE__ << endl;

 	//check assert usage
 	string filename;
 	assert(filename != "");

 	// check whether include additional header file wil increase the binary size?
 	// the answer is no, but define object will.
 	ofstream outfile( "out_file" );
 	ifstream infile( "input_file" );
}

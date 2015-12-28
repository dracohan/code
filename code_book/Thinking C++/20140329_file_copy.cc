#include <fstream>

using namespace std;

int 
main()
{
	ofstream ofs("out.log");
	ifstream ifs("in.log");
	string s;

	while(getline(ifs,s))
	{
		ofs << "" << s << endl;
	}
	return 0;
}
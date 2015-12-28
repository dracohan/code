#include <iostream>
using namespace std;

/*
#include <vector>

int main()
{
	vector<int> ivec;

	for(int i = 1; i < 8; ++i)
		ivec.push_back(i);

	vector<int>::iterator iter = ivec.begin();

	for(; iter != (ivec.end() - 1); iter++)
		cout << *iter << " | ";

	cout << *(iter);

	return 0;
}


#include <deque>
int main()
{
	deque<float> fdeque; 

	for(float f = 1.1; f < 9.9; f += 1.1)
		fdeque.push_front(f);

	int i = 0;

	for(; i < (fdeque.size() - 1); i++)
		cout << fdeque[i] << " | ";

	cout << fdeque[i] << endl;

	return 0;
}

#include <list>
int main() 
{
	list<char> clist;

	//can't put iter initialization here
	//because clist is empty now, iter will be NULL
	//list<char>::iterator iter = clist.begin();	
	
	for(char c = 'a'; c < 'f'; ++c)
		clist.push_back(c);

	list<char>::iterator iter = clist.begin();	

	for(; iter != (--clist.end()); ++iter)
		cout << *iter << " | ";

	cout << *(iter);

	return 0;
}

#include <set>
int main()
{
	typedef set<int> IntSet;

	IntSet iset;
	iset.insert(1);
	iset.insert(12);
	iset.insert(6);
	iset.insert(9);

	set<int>::iterator iter = iset.begin();
	
	for(; iter != (--iset.end()); ++iter)
		cout << *iter << " | ";

	cout << *(iter);

	return 0;
}


#include <map>
#include <utility>

int main()
{
	typedef map<int, string> IntStrMap;

	IntStrMap ismap;
	ismap.insert(make_pair(1, "this"));
	ismap.insert(make_pair(3, "unbelievable"));
	ismap.insert(make_pair(2, "a"));
	ismap.insert(make_pair(4, "succeed"));
	ismap.insert(make_pair(1, "is"));

	map<int, string>::iterator iter;

	for(iter = ismap.begin(); iter != (--ismap.end()); ++iter)
	{
		cout << iter->second << " | ";
	}
	cout << iter->second;
}

#include <map>
int main()
{
	typedef map<int, string> IntStrMap;
	IntStrMap ismap;

	ismap[1] = "This";
	ismap[3] = "a";
	ismap[4] = "map";
	ismap[2] = "is";
	ismap[5] = ".";

	IntStrMap::iterator iter;
	for(iter = ismap.begin(); iter != (--ismap.end()); ++iter)
	{
		cout << "Key: " << iter->first << "\t" << "Value: " << iter->second << endl;
	}

	cout << "Key: " << iter->first << "\t" << "Value: " << iter->second << endl;
	
}
*/

#include <iostream>

template <class Container>
void printCollection(const Container &c, const char* optcstr="")
{
	if(c.empty())
		std::cout << "empty" << std::endl;
	else 
	{
		typename Container::const_iterator citer = c.begin();
		std::cout << optcstr;	
		for(; citer != c.end(); citer++)
			std::cout << " " << *citer;
		std::cout << std::endl;	
	}
}


/*
int main() 
{
	vector<int> vint;
	vector<string> vstr;
	for(int i = 0; i < 5; i++)
		vint.push_back(i);
	
	printCollection(vint);
	printCollection(vstr);
}
*/	


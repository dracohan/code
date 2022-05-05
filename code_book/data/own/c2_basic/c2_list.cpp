///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   c2_list.cpp
//  Author      :   Jimmy Han
//  Date        :   N.A 			    v1    
//              :   2014/07/13 12:30    v2    
//
///////////////////////////////////////////////////////////////////////////////
#include "printCollection.h"
#include "c2_list.h"
using namespace std;

int main()
{
	//List();
	List<string> slist;

	//erase empty list;
	cout << "1: When trying to erase an empty list: " << endl;
	slist.erase(slist.begin());

	//void push_back(const object &x)
	slist.push_back("a1");
	slist.push_back("a2");
	slist.push_front("b1");
	slist.push_front("b2");

	//object& getat(const int idx)
	cout << "2: The second item of list is: " << endl;
	cout << slist.getat(2) << endl;

	//show content
	cout << "3: The content of list is: " << endl;
	printCollection(slist);

	//object& front()
	cout << "4: The first item of list is: " << endl;
	cout << "Front is: " << slist.front() << endl;

	//List(const List& rhs);
	List<string> slist2 = slist;
	
	//void push_front(const object &x)
	//c2 c1 b2 b1 a1 a2
	slist2.push_front("c1");
	slist2.push_front("c2");
		
	//void pop_back()
	//c2 c1 b2 b1 a1
	slist2.pop_back();
	
	//void pop_front()
	//c1 b2 b1 a1 
	slist2.pop_front();
	
	//object & front()
	cout << "5: The first item of list is: " << endl;
	cout << slist2.front() << endl;
	
	//object & back()
	cout << "6: The last item of list is: " << endl;
	cout << slist2.back() << endl;
	
	//iterator insert(const iterator &iter, object &x)
	//d1 c1 b2 b1 a1
	slist2.insert(++(slist2.begin()), "d1");
	
	//erase(const_iterator iter)
	// c1 b2 b1 a1 a2
	slist2.erase((slist2.begin())++);
	
	//begin(), end()
	cout << "7: The content of list is: " << endl;
	for(List<string>::const_iterator iter = slist2.begin(); iter != slist2.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	
	cout << "8: The content of list is: " << endl;
	printCollection(slist);
	
	return 0;
}



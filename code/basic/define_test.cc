///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   define_test.cc
//  Version     :   0.10	created	2014/05/24 11:27:00		
//  Author      :   Jimmy Han
//  Comment     :  预定义宏检测
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include "define_test.h"

using namespace std;

int 
main()
{
	# if defined(__sgi)
		cout << "__sgi defined 1" << endl;
	# else
		#define __sgi
	# endif

	# if defined(__sgi)
		cout << "__sgi defined 2" << endl;
	# endif

	# if defined(_STL_NEED_TYPENAME)
		cout << "_STL_NEED_TYPENAME defined" << endl;
	# else
		cout << "_STL_NEED_TYPENAME undefined" << endl;
	#endif

	// # if defined(__STL_STATIC_TEMPLATE_MEMBER_BUG)
	// 	cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG defined" << endl;
	// # else
	// 	cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG undefined" << endl;
	// #endif
}
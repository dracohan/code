///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   swap_item25.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 13:13:55
//					2013/10/30 08:27:50
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
  
#include "swap_item25.h"
#include <iostream>
using namespace std;


		
int main()
{
	Widget a;
	Widget b(4,5,6);
	
	a.WidgetPrint();
	b.WidgetPrint();
	
	swap(a, b);
	
	a.WidgetPrint();
	b.WidgetPrint();
	
	int* pinta = new int(5);
	int* pintb = pinta;
	
	
	cout << "*pinta is: " << *pinta << endl;
	cout << "*pintb is: " << *pintb << endl;
	
	return 0;	
}

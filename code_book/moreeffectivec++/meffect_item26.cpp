///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item26.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/18
//  Comment     :	
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "meffect_item26.h"
using namespace PrintingStuff;


int main(){
	thePrinter();

	Scanner* pscan1 = Scanner::makeScanner();
	delete pscan1;
	Scanner* pscan2 = Scanner::makeScanner();
	Scanner* pscan3 = Scanner::makeScanner();
	Scanner* pscan4 = Scanner::makeScanner();
	delete pscan2;
	delete pscan3;
	delete pscan4;

	return 0;
}
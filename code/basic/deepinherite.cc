///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   deepinherite.cc
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/12/02
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "deepinherite.h"
using namespace std;

void
B1::B1F1(){
	cout << "B1F1" << endl;
}

void
B1::B1F2(){
	cout << "B1F2" << endl;
}

void
B1::B1F3(){
	cout << "B1F3" << endl;
}

void
D1::D1T(){
	//public function is accessible
	B1F1();
	//protected function is accessible
	B1F2();
	//private function is NOT accessible
	//B1F3();
}

void
D2::D2T(){
	//layer 2 public function is accessible
	B1F1();
	//layer 2 protected function is accessible
	B1F2();
	//layer 2 private function is NOT accessible
	//B1F3();
}

void
D3::D3T(){
	//layer 2 public function is accessible
	B1F1();
	//layer 2 protected function is accessible
	B1F2();
	//layer 2 private function is NOT accessible
	//B1F3();
}
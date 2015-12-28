///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   const_array.h
//  Version     :   0.10	created	2014/05/10 16:00:00	
//  Author      :   Jimmy Han
//  Comment     :  const 成员必须在初始化列表初始化
//					const数组必须在类外初始化
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Base{
public:
	//constructor
	//deconstructor
	//public function
	Base() : _cia(1){cout << "Base constructor was called" << endl;}
	void get();
	//public member
protected:
	//protected function
	//protected member
private:
	//private function
	//provate member
	const int _cia;
	static const int _ciaa[10];
};

class Derive : public Base{
public:
	//constructor
	//deconstructor
	//public function
	//public member
protected:
	//protected function
	//protected member
private:
	//private function
	//provate member

};



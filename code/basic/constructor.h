///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   constructor.h
//  Version     :   0.10	created	2013/11/09 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Elem1{
	public:
	Elem1(int x){
		cout << "Elem1() was called." << endl;
	}
	~Elem1(){
		cout << "~Elem1() was called." << endl;
	}
};

class Elem2{
	public:
	Elem2(int x){
		cout << "Elem2() was called." << endl;
	}
	~Elem2(){
		cout << "~Elem2() was called." << endl;
	}
};

class Elem3{
	public:
	Elem3(int x){
		cout << "Elem3() was called." << endl;
	}
	~Elem3(){
		cout << "~Elem3() was called." << endl;
	}
};

class Elem4{
	public:
	Elem4(int x){
		cout << "Elem4() was called." << endl;
	}
	~Elem4(){
		cout << "~Elem4() was called." << endl;
	}
};


class Base{
public:
	Base(int):_elem2(Elem2(2)), _elem1(Elem1(1)), _elem3(Elem3(3)){
		cout << "Base() was called." << endl;
	}
	~Base(){
		cout << "~Base() was called." << endl;
	}
private:
	Elem1 _elem1;
	Elem2 _elem2;
	Elem3 _elem3;
};

class Derive : public Base{
public:
	//if there is no default constructor for base class, it has to be called explicit in derive class
	//four scenarios to use initialization list must:
	//1. Base. base class don't have Base();
	//2. const int b. class member is const 
	//3. int& c. class member is reference
	//4. _elem4. class member dont' have default constructor.
	Derive():Base(1), _elem4(Elem4(4)), b(3), c(b){
		cout << "Derive() was called." << endl;
	}
private:
	Elem4 _elem4;
	const int b;
	const int& c;

};



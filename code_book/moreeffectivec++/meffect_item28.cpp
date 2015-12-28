///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item28.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/28
//  Comment     :	auto_ptr init, copy, NULL judgement, const 
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <memory>
#include "meffect_item28.h"


int main(){
	//auto_ptr is equal to following two sentence.
	//B* pbb = new B;
	//delete pbb;
	auto_ptr<B> pb(new B);

	//auto_ptr will be init to 0 if no arg provided.
	auto_ptr<B> pb1;

	//auto_ptr could be copied but owner will be transferred too
	//only one owner allowed, so only one time delete B will be called.	
	//or call delete twice is a disaster
	auto_ptr<B> pb2 = pb;	

	//judge whether auto_ptr is null
	//if(!pb)
	//	cout << "auto_ptr point to nothing." << endl;

	//normal B* could be converted to const B*
	B* pb3 = new B;
	const B* pb4 = pb3;
	delete pb4;

	//However, auto_ptr<B> can NOT be converted to auto_ptr<const B>
	auto_ptr<B> pb5(new B);
	//auto_ptr<const B> pb6 = pb5;
	
	//this is a const auto_ptr
	const auto_ptr<B> pb7 = pb5;
	
	//could be init by heap pointer, but can't be init by B b; auto_ptr<B> pb9(&b);
	B* pb8 = new B;
	auto_ptr<B> pb9(pb8);

}
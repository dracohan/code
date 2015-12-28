///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item27.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/26
//  Comment     :	restrict object not to heap
//
///////////////////////////////////////////////////////////////////////////////
#ifndef MEFFECT_ITEM27_H
#define	MEFFECT_ITEM27_H
#include <iostream>
using namespace std;
class B{
public:
	//const to deconstructed const object also	
	void destroy() const{delete this;}
private:
	//private deconstructor will permit only heap allocation 
	~B();
};

class D : public B{

};

class E{
public:
	E():pb(new B()){}
	~E(){pb->destroy();}
	//embed B b is NOK, but B* b is OK. 
	B* pb;

};
#endif
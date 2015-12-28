///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item34.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 14:40:03
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#ifndef EFFECT_ITEM34_H
#define EFFECT_ITEM34_H

class Base {
	public: 
		//item36
		//parameter is compile behavior, while virtual is run-time behavrior
		//don't redefine inherited default parameter
		enum ShapeColor {RED, GREEN, BLUE};
		virtual void draw(ShapeColor color = RED) const;

		//item34
		//different inherit functions
		virtual void pureFunc() = 0;
		virtual void virtualFunc(); 
		void nonvirtualFunc();

		//item35
		void virtualFunc2Wrapper();
	protected:
		virtual void virtualFunc2();

};

class Derive : public Base {
	public:
		//implement pure virtual function and make it non pure
		virtual void pureFunc();
		virtual void draw(ShapeColor color = GREEN) const;
	private:
		virtual void virtualFunc2();
};

#endif